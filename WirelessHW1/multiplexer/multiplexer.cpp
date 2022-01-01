


#include  "multiplexer.h"
#include <math.h>
#include <iostream>
#include <string>


int64_t MultiplexerOne::frame_to_packets(std::vector<int64_t>* frames)
{
	if (frames->size() == 0)
		return -1;
	
	int64_t frame_bits = frames->at(0);
	frames->erase(frames->begin());

	//int64_t  packet_number = frame_bits % (8 * 80) == 0 ? frame_bits / (8 * 80) : int64_t(frame_bits / (8 * 80)) + 1;
	int64_t  packet_number = frame_bits % (8 * 120) == 0 ? frame_bits / (8 * 120) : int64_t(frame_bits / (8 * 120)) + 1;
	all_packets += packet_number;
	
	return packet_number;
}


void MultiplexerOne::write_in_buffer()
{
	if (packet_to_send >0 && packet_to_receive < buffer_size)
	{
		packet_to_send--;
		packet_to_receive++;
	}

	if (packet_to_send >0 && packet_to_receive >= buffer_size)
	{
		packet_to_send--;
		all_lost_packets++;
	}
	
}

void MultiplexerOne::read_frome_buffer()
{
	if(packet_to_receive>0)
	{
		packet_to_receive--;
	}
}
