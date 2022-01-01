#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <math.h>

#include  "MultiplexerTest.h"
#include  "../multiplexer/multiplexer.h"

using namespace std;

void Tests::OneMultiplexer()
{
	//Jurrasic Park //Silence of Lambs //Star Wars
	string line;
	std::ifstream infile("./Resource/Star Wars.txt");

	// read from file and store to frames vector
	vector<int64_t> temp;
	vector<int64_t>* frames = &temp;
	if (infile.is_open())
	{
		while (getline(infile, line))
			frames->push_back(stoi(line));
		infile.close();
	}
	else cout << "Unable to open file \n";

	MultiplexerOne multiplexer;

	int64_t new_frame_packets = 0;

	int64_t fist_timer = 0;//based on microsecond
	int64_t second_timer = 0;//based on microsecond
	int64_t third_timer = 0;//based on microsecond

	int32_t stop = 0;
	int32_t BWeff[2] = { 327, 328 };
	int32_t Rate = BWeff[0];
	
	while (true)
	{
		//Generate packet process
		if (fist_timer == 40000)
		{
			new_frame_packets = multiplexer.frame_to_packets(frames);
			if (new_frame_packets == -1)
			{
				stop++;
				break;
			}
				

			multiplexer.set_packet_to_send(new_frame_packets);

			fist_timer = 0;
		}

		//Write in buffer process
		if (second_timer == 21)
		{
			multiplexer.write_in_buffer();
			second_timer = 0;
		}

		//Read from buffer process //2935
		if (third_timer == int64_t(120*8*1000*1.0/ 223 ))
		{
			multiplexer.read_frome_buffer();
			third_timer = 0;
		}

		fist_timer++;
		second_timer++;
		third_timer++;
	}

	printf("All packets is:%i\n", multiplexer.get_all_packets());
	printf("All lost packet is:%i\n", multiplexer.get_lost_packets());
	printf("Packet Loss Ratio(PLR) is: %f\n", (multiplexer.get_lost_packets()*1.0 / multiplexer.get_all_packets()*1.0));
}