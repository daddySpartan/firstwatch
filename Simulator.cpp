// Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "Simulation.h"

/*//uncomment to check execution speed for optimization exercise
#include <chrono>*/

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Simulator.exe <simfile> [json]" << std::endl;
        std::cout << "simulation output is in circuit.jsonp" << std::endl;
        exit(0);
    }
    bool json = (argc >= 3 && "json" == std::string(argv[2]));
    std::ifstream input(argv[1], std::ios::in);
	if (!input.is_open())
	{
		std::cout << "Could not open file " << argv[1] << std::endl;
		exit(1);
	}   

    auto simulation = Simulation::FromFile(input);
    simulation->LayoutFromFile(input);   
    simulation->ProbeAllGates();      

    /*// Get the start time
    auto start4 = std::chrono::high_resolution_clock::now();*/
    simulation->Run();
    /*// Get the end time
    auto end4 = std::chrono::high_resolution_clock::now();
    // Calculate the duration
    auto duration4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - start4).count();
    std::cout << "Function: Simulation::Run " << "Time taken: " << duration4 << " milliseconds" << std::endl;*/

    if (json)
    {
        simulation->UndoProbeAllGates();

        //boost::property_tree::ptree simResult = simulation->GetJson();
        std::ofstream output("circuit.jsonp", std::ios::out);
 
        /*// Get the start time
        auto start7= std::chrono::high_resolution_clock::now();*/
        //boost::property_tree::write_json(output, simResult);
		simulation->WriteJsonOutput(output);
        /*// Get the end time
        auto end7 = std::chrono::high_resolution_clock::now();
        // Calculate the duration
        auto duration7 = std::chrono::duration_cast<std::chrono::milliseconds>(end7 - start7).count();
        std::cout << "Function: write to json file " << "Time taken: " << duration7 << " milliseconds" << std::endl;*/
    }
    simulation->PrintProbes(std::cout);
 }
