#include <algorithm>
#include <stdexcept>
#include <sstream>

template<typename T>
void Graph<T>::add_vertex(T& vertex)
{
	name_to_reference_.insert(std::make_pair(vertex.get_name(), &vertex));
}

template<typename T>
void Graph<T>::add_vertex(T* vertex)
{
	name_to_reference_.insert(std::make_pair(vertex->get_name(), vertex));
}

template<typename T>
void Graph<T>::remove_vertex(T& vertex)
{
	ensure_exists(vertex);
	remove_incoming_and_outgoing_edges(&vertex);
	name_to_reference_[vertex.get_name()] = NULL;
}

template<typename T>
void Graph<T>::remove_vertex(std::string name)
{
	ensure_exists(name);
	T* vertex = name_to_reference_[name];
	remove_incoming_and_outgoing_edges(vertex);
	name_to_reference_[vertex->get_name()] = NULL;
}

template<typename T>
void Graph<T>::remove_incoming_and_outgoing_edges(T* vertex)
{
	typename std::map< T*, std::list< Edge<T> > >::iterator itr = graph_.begin();
	while(itr != graph_.end())
	{
		// Remove the entry from the graph_ map which contains the outgoing edges
		if(itr->first == vertex)
			graph_[vertex].clear();
		else
		{
			// Look for an edge going to the vertex in question
			std::list< Edge<T> > cur_edges = itr->second;
			typename std::list< Edge<T> >::iterator itr2 = cur_edges.begin();
			while(itr2 != cur_edges.end())
			{
				// If you find such an edge
				if(itr2->get_destination() == vertex)
				{
					// Remove it
					Edge<T> edge(itr2->get_destination(), itr2->get_weight());
					(itr->second).remove(edge);
				}
				++itr2;
			}
		}
		++itr;
	}
}

template<typename T>
std::list<T*> Graph<T>::get_vertices() const
{
	std::list<T*> result;

	typename std::map<std::string,T*>::const_iterator itr = name_to_reference_.begin();
	while(itr != name_to_reference_.end())
	{
		result.push_back(itr->second);
		++itr;
	}

	return result;
}

template<typename T>
void Graph<T>::add_edge(T& from, T& to, long weight)
{
	ensure_both_exist(from, to);
	
	graph_[&from].push_back(Edge<T>(&to, weight));
}

template<typename T>
void Graph<T>::add_edge(std::string from, std::string to, long weight)
{
	ensure_both_exist(from, to);

	T* source_vertex = name_to_reference_[from];
	T* destination_vertex = name_to_reference_[to];
	graph_[source_vertex].push_back(Edge<T>(destination_vertex, weight));
}

template<typename T>
void Graph<T>::ensure_exists(const T& v)
{
	if(name_to_reference_.find(v.get_name()) == name_to_reference_.end() || 
	name_to_reference_[v.get_name()] == NULL)
	{
		std::stringstream s;
		s << "Missing key \"" << v.get_name() << "\"";
		throw std::runtime_error(s.str());
	}
}

template<typename T>
void Graph<T>::ensure_exists(std::string name)
{
	if(name_to_reference_.find(name) == name_to_reference_.end() ||  
	name_to_reference_[name] == NULL)
	{
		std::stringstream s;
		s << "Missing key \"" << name << "\"";
		throw std::runtime_error(s.str());
	}
}

template<typename T>
void Graph<T>::ensure_both_exist(const T& from, const T& to)
{
	ensure_exists(from);
	ensure_exists(to);
}

template<typename T>
void Graph<T>::ensure_both_exist(std::string from, std::string to)
{
	ensure_exists(from);
	ensure_exists(to);
}

template<typename T>
std::list< Edge<T> > Graph<T>::get_edges_from(T& vertex)
{
	ensure_exists(vertex);
	return graph_[&vertex];
}

template<typename T>
std::list< Edge<T> > Graph<T>::get_edges_from(std::string name)
{
	ensure_exists(name);
	return graph_[name_to_reference_[name]];
}

template<typename T>
bool Graph<T>::are_adjacent(const T& src, const T& dest)
{
	ensure_both_exist(src, dest);
	return neighbor_list_contains(&src, &dest);
}

template<typename T>
bool Graph<T>::are_adjacent(std::string first_name, std::string second_name)
{
	ensure_both_exist(first_name, second_name);

	T* first = name_to_reference_[first_name];
	T* second = name_to_reference_[second_name];
	
	return neighbor_list_contains(first, second);
}

template<typename T>
bool Graph<T>::neighbor_list_contains(const T* src, const T* target)
{
	std::list< Edge<T> > neighbors = graph_[(T*)src];
	typename std::list< Edge<T> >::const_iterator itr = neighbors.begin();
	while(itr != neighbors.end())
	{
		if(itr->get_destination() == target)
			return true;
		++itr;
	}
	return false;
}

template<typename T>
std::list<T*> Graph<T>::neighbors(const T& vertex)
{
	ensure_exists(vertex);
	return get_unique_adjacent_vertices(&vertex);
}

template<typename T>
std::list<T*> Graph<T>::neighbors(std::string name)
{
	ensure_exists(name);
	return get_unique_adjacent_vertices(name_to_reference_[name]);
}

template<typename T>
std::list<T*> Graph<T>::get_unique_adjacent_vertices(const T* src)
{
	std::list<T*> result;
	std::list< Edge<T> > edges = graph_[(T*)src];
	typename std::list< Edge<T> >::const_iterator itr = edges.begin();
	while(itr != edges.end())
	{
		bool found = (std::find(result.begin(), result.end(), itr->get_destination()) != result.end());
		if(!found)
			result.push_back(itr->get_destination());
		++itr;
	}
	return result;
}

template<typename T>
void Graph<T>::remove_edge(std::string from_name, std::string to_name, long weight)
{
	ensure_both_exist(from_name, to_name);

	T* from = name_to_reference_[from_name];
	T* to = name_to_reference_[to_name];

	remove_edge_if_exists(from, to, weight);
}

template<typename T>
void Graph<T>::remove_edge(const T& from, const T& to, long weight)
{
	ensure_both_exist(from, to);

	remove_edge_if_exists(&from, &to, weight);
}

template<typename T>
void Graph<T>::remove_edge_if_exists(const T* from, const T* to, long weight)
{
	Edge<T> edge((T*)to, weight);
	std::list< Edge<T> > edges = graph_[(T*)from];

	typename std::list< Edge<T> >::const_iterator contains = 
		std::find(edges.begin(), edges.end(), edge);
	if(contains == edges.end())
		throw std::runtime_error("The edge doesn't exist!");
	
	graph_[(T*)from].remove(edge);
}

template<typename T>
std::list<T*> Graph<T>::get_path(const T& from, const T& to)
{
	ensure_both_exist(from, to);

	T* src = (T*) &from;
	T* dest = (T*) &to;

	std::list<T*> result;
	std::map<T*,bool> visited;
	return dfs_get_path(src, dest, result, visited);
}

template<typename T>
std::list<T*> Graph<T>::get_path(std::string from, std::string to)
{
	ensure_both_exist(from, to);

	T* src = name_to_reference_[from];
	T* dest = name_to_reference_[to];

	std::list<T*> result;
	std::map<T*,bool> visited;
	return dfs_get_path(src, dest, result, visited);
}

template<typename T>
std::list<T*> Graph<T>::dfs_get_path(const T* src, const T* dest, 
	std::list<T*>& result, std::map<T*,bool>& visited)
{
	visited[(T*)src] = true;
	result.push_back((T*)src);

	if(src == dest)
	{
		return result;
	}

	std::list<T*> neighbors_list = neighbors(src->get_name());
	typename std::list<T*>::const_iterator itr = neighbors_list.begin();
	
	// Reached dead end
	if(itr == neighbors_list.end())
	{
		result.remove((T*)src);
		return std::list<T*>(); // basically "false"
	}

	while(itr != neighbors_list.end())
	{
		if(!visited[*itr])
		{
			std::list<T*> res = dfs_get_path(*itr, dest, result, visited);
			if(!res.empty())
				return res;
		}
		++itr;
	}

	result.remove((T*)src);

	return std::list<T*>();
}