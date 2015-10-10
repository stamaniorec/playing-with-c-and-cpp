#ifndef __GRAPH__
#define __GRAPH__

#include "edge.hpp"
#include <list>
#include <map>
#include <string>

template<typename T>
class Graph
{
	std::map<std::string,T*> name_to_reference_;
	std::map< T*, std::list< Edge<T> > > graph_;

	void ensure_exists(const T& v);
	void ensure_exists(std::string name);

	void ensure_both_exist(const T& from, const T& to);
	void ensure_both_exist(std::string from, std::string to);

	bool neighbor_list_contains(const T* source, const T* target);
	std::list<T*> get_unique_adjacent_vertices(const T* src);
	void remove_edge_if_exists(const T* from, const T* to, long weight);

	std::list<T*> dfs_get_path(const T* src, const T* dest, 
		std::list<T*>& result, std::map<T*,bool>& visited);

	void remove_incoming_and_outgoing_edges(T* vertex);
public:
	Graph() {};

	void add_vertex(T& vertex);
	void add_vertex(T* vertex);

	void remove_vertex(T& vertex);
	void remove_vertex(std::string name);

	std::list<T*> get_vertices() const;

	void add_edge(T& from, T& to, long weight);
	void add_edge(std::string from, std::string to, long weight);

	std::list< Edge<T> > get_edges_from(T& vertex);
	std::list< Edge<T> > get_edges_from(std::string name);

	bool are_adjacent(const T& first, const T& second);
	bool are_adjacent(std::string first_name, std::string second_name);

	std::list<T*> neighbors(const T& vertex);
	std::list<T*> neighbors(std::string name);

	void remove_edge(std::string from_name, std::string to_name, long weight);
	void remove_edge(const T& from, const T& to, long weight);

	std::list<T*> get_path(const T& from, const T& to);
	std::list<T*> get_path(std::string from, std::string to);
};

#include "graph.tcc"

#endif