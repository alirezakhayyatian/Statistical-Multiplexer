
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

#include  "MultiplexerTest.h"
#include  "../multiplexer/multiplexer.h"

using namespace std;

void Tests::ThreeMultiplexer()
{
	//Jurrasic Park
	string line;
	std::ifstream infile("./Resource/Jurrasic Park.txt");

	// read from file and store to frames vector
	vector<int64_t> temp[3];
	vector<int64_t>* frames[3]={&temp[0],&temp[1] ,&temp[2] } ;
	if (infile.is_open())
	{
		while (getline(infile, line))
			frames[0]->push_back(stoi(line));
		infile.close();
	}
	else cout << "Unable to open file \n";


	//Silence of Lambs
	string line2;
	std::ifstream infile2("./Resource/Silence of Lambs.txt");

	// read from file and store to frames vector

	if (infile2.is_open())
	{
		while (getline(infile2, line2))
			frames[1]->push_back(stoi(line2));
		infile2.close();
	}
	else cout << "Unable to open file \n";


	//Star Wars 
	string line3;
	std::ifstream infile3("./Resource/Star Wars.txt");

	// read from file and store to frames vector

	if (infile3.is_open())
	{
		while (getline(infile3, line3))
			frames[2]->push_back(stoi(line3));
		infile3.close();
	}
	else cout << "Unable to open file \n";


	MultiplexerOne multiplexer;

	int64_t new_frame_packets = 0;

	int64_t fist_timer[3] = { 0,-150000,-300000 };//based on microsecond
	int64_t second_timer[3] = { 0 };//based on microsecond
	int64_t third_timer[3] = { 0 };//based on microsecond



	bool user_stop[3] = {false,false,false};
	
	
	while (true)
	{
		for (int32_t user = 0; user < 3; user++)
		{

			//Generate packet process
			if (fist_timer[user] == 40000 && !user_stop[user])
			{
				new_frame_packets = multiplexer.frame_to_packets(frames[user]);
				if (new_frame_packets == -1)
					user_stop[user]=true;

				multiplexer.set_packet_to_send(new_frame_packets);

				fist_timer[user] = 0;
			}

			//Write in buffer process
			if (second_timer[user] == 21)
			{
				multiplexer.write_in_buffer();
				second_timer[user] = 0;
			}

			//Read from buffer process //2935
			if (third_timer[user] == int64_t(120 * 8 * 1000 * 1.0 / 255))
			{
				multiplexer.read_frome_buffer();
				third_timer[user] = 0;
			}

			fist_timer[user]++;
			second_timer[user]++;
			third_timer[user]++;

		}

		if (user_stop[2]==true && user_stop[1] == true && user_stop[0] == true  )
			break;
	}

	printf("All packets is:%i\n", multiplexer.get_all_packets());
	printf("All lost packet is:%i\n", multiplexer.get_lost_packets());
	printf("Packet Loss Ratio(PLR) is: %f\n", multiplexer.get_lost_packets()*1.0 / multiplexer.get_all_packets()*1.0);
	
}