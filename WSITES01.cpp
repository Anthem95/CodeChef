// WSITES01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

// Iterates through the vector and finds the blocked sites & sorts them into a vector
std::vector<std::string> bFinder(std::vector<std::string> sites);

// Iterates through the vector and finds unblocked sites & sorts them into a vector
std::vector<std::string> unbFinder(std::vector<std::string> sites);

// Compares blocked sites to the unbl vector to find the shortest prefix, returns a vector of filters
std::vector<std::string> filterFinder(std::vector<std::string> unblocked, std::vector<std::string> blocked);


int main()
{
	int N; 
	std::string site;
	std::vector<std::string> sites;
	std::vector<std::string> blocked; 
	std::vector<std::string> unblocked; 
	std::vector<std::string> filters;
	
	//std::cout << "Please input the # of sites: " << std::endl;
	std::cin >> N;
	std::cin.ignore();

	for (int n = 0; n < N; n++) 
	{
		std::getline(std::cin, site);
		sites.push_back(site); 


	
	}

	blocked = bFinder(sites);
	unblocked = unbFinder(sites);
	filters = filterFinder(unblocked, blocked);

	std::vector < std::string>::iterator it;
	int sz = filters.size();
	std::cout << sz << '\n' << std::endl;
	for (it = filters.begin(); it < filters.end(); it++) {
		std::cout << *it << std::endl;
	}


	

    return 0;
}

std::vector<std::string> bFinder(std::vector<std::string> sites) {
	
	std::vector<std::string> blocked; 
	std::vector<std::string>::iterator it;
	std::string s;
	char c;
	for (it = sites.begin(); it < sites.end(); it++) {
		std::cout << *it;
		s = *it;
		c = s[0];
		if (c == '-') {
			blocked.push_back(*it);
		}
	}

	it = blocked.begin();
	std::cout << "blocked: " << *it << "  ";
	it = blocked.end() - 1;

	return blocked;
}


std::vector<std::string> unbFinder(std::vector<std::string> sites) {
	std::vector<std::string> unblocked;
	std::vector<std::string>::iterator it;
	std::string s;
	char c;
	for (it = sites.begin(); it < sites.end(); it++) {
		s = *it;
		c = s[0];
		if (c == '+') {
			unblocked.push_back(*it);
		}
	}

	return unblocked;
}

std::vector<std::string> filterFinder(std::vector<std::string> unblocked, std::vector<std::string> blocked) {
	
	std::string sitename;
	std::string comp, cmp;
	std::vector<std::string> filters;
	std::vector<std::string>::iterator bit;
	std::vector<std::string>::iterator is;
	int flag;
	std::string prefix;
	// Run through the blocked sitelist
	BLOCKED: for (bit = blocked.begin(); bit < blocked.end(); bit++)
	{
		
		
		sitename = *bit;

		// For each blocked entry, check for a match against the unblocked sitelist.
		// Starting from the 1st letter of the blocked entry, growing to the last so we can find
		// the smallest possible filter name.

		// iterate through the string (single element) that is an entry in the blocked list
		for (int n = 2; n < sitename.length(); n++) 
		{
			flag = 0;
			prefix = sitename.substr(2, n -1);
			
			// iterate through the unblocked list
			for (is = unblocked.begin(); is < unblocked.end(); is++) 
			{
				comp = *is;
				cmp = comp.substr(2, n - 1); // create a substring of the same length to compare prefix to.

				// if prefix equals an unblocked item, it's no good. The prefix needs to be longer.
				if (prefix == cmp)
				{
					flag = 1;
					break;
				}
				else if ((is == (unblocked.end()-1)) && (prefix != cmp) && (flag == 0))
				{	// means a suitable filter is found, and this is the last item on the list.
					filters.push_back(prefix);
					prefix.clear();
					flag = 2;
					break;
				}
				
			}

			if (flag == 2)
				break;
				
			
		}
		
		
	}
	
	
	return filters;
}

