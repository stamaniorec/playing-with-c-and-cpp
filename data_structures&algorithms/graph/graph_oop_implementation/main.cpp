#include <iostream>
#include <map>
#include <list>

#include "graph.hpp"
#include "edge.hpp"
#include "city.hpp"

int main(int argc, char const *argv[])
{
	City c("Sofia", 1300000);
	City c2("Plovdiv", 370000);
	City c3("Varna", 348000);

	Graph<City> g;
	g.add_vertex(new City("Luneville", 123123));
	g.add_vertex(c);
	g.add_vertex(c2);
	g.add_vertex(c3);

	g.add_edge(c, c2, 120);
	g.add_edge(c, c3, 500);
	g.add_edge(c, c2, 130);
	g.add_edge("Sofia", "Luneville", 32100);
	g.add_edge("Luneville", "Plovdiv", 190);

	std::cout << "--- Cities ---" << std::endl;

	std::list<City*> cities = g.get_vertices();
	std::list<City*>::const_iterator itr = cities.begin();
	while(itr != cities.end())
	{
		std::cout << *itr << std::endl;
		++itr;
	}

	std::cout << "--- Roads from Sofia ---" << std::endl;

	std::list< Edge<City> > roads = g.get_edges_from(c);
	std::list< Edge<City> >::const_iterator itr2 = roads.begin();
	while(itr2 != roads.end())
	{
		std::cout << *itr2 << std::endl;
		++itr2;
	}

	std::cout << "--- Roads from Luneville ---" << std::endl;

	std::list< Edge<City> > roads2 = g.get_edges_from("Luneville");
	std::list< Edge<City> >::const_iterator itr3 = roads2.begin();
	while(itr3 != roads2.end())
	{
		std::cout << *itr3 << std::endl;
		++itr3;
	}

	std::cout << "--- Adjacency tests ---" << std::endl;

	std::cout << "Is Sofia adjacent to Plovdiv? " << g.are_adjacent(c, c2) << std::endl;
	std::cout << "Is Plovdiv adjacent to Sofia? " << g.are_adjacent(c2, c) << std::endl;
	std::cout << "Is Luneville adjacent to Varna? " << g.are_adjacent("Luneville", "Varna") << std::endl;
	std::cout << "Is Sofia adjacent to Luneville? " << g.are_adjacent("Sofia", "Luneville") << std::endl;

	std::cout << "--- Neighbors of Sofia ---" << std::endl;

	std::list<City*> neighbors_of_sofia = g.neighbors("Sofia");
	std::list<City*>::const_iterator neighbors_iterator = neighbors_of_sofia.begin();
	while(neighbors_iterator != neighbors_of_sofia.end())
	{
		std::cout << *neighbors_iterator << std::endl;
		++neighbors_iterator;
	}

	g.remove_edge("Sofia", "Plovdiv", 130);
	// g.remove_edge("Sofia", "Varna", 500);

	std::cout << "--- Roads from Sofia again ---" << std::endl;

	std::list< Edge<City> > roads3 = g.get_edges_from(c);
	std::list< Edge<City> >::const_iterator roads_itr = roads3.begin();
	while(roads_itr != roads3.end())
	{
		std::cout << *roads_itr << std::endl;
		++roads_itr;
	}

	g.add_edge("Plovdiv", "Varna", 300);

	std::cout << "--- Roads from Plovdiv ---" << std::endl;

	std::list< Edge<City> > roads4 = g.get_edges_from("Plovdiv");
	std::list< Edge<City> >::const_iterator roads_itr2 = roads4.begin();
	while(roads_itr2 != roads4.end())
	{
		std::cout << *roads_itr2 << std::endl;
		++roads_itr2;
	}

	City b("Burgas", 200000);
	g.add_vertex(b);
	g.add_edge("Varna", "Burgas", 20);
	std::cout << "--- Path from Sofia to Burgas ---" << std::endl;

	std::list<City*> path = g.get_path("Sofia", "Burgas");
	std::list<City*>::const_iterator path_itr = path.begin();
	while(path_itr != path.end())
	{
		std::cout << *path_itr << std::endl;
		++path_itr;
	}

	g.remove_vertex(c3);

	std::cout << "--- Roads from Plovdiv after deleting Varna---" << std::endl;
	roads4 = g.get_edges_from("Plovdiv");
	roads_itr2 = roads4.begin();
	while(roads_itr2 != roads4.end())
	{
		std::cout << *roads_itr2 << std::endl;
		++roads_itr2;
	}

	std::cout << "--- Roads from Sofia after deleting Varna ---" << std::endl;

	roads3 = g.get_edges_from(c);
	roads_itr = roads3.begin();
	while(roads_itr != roads3.end())
	{
		std::cout << *roads_itr << std::endl;
		++roads_itr;
	}

	g.get_edges_from("Varna");

	return 0;
}