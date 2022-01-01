
#include <cstdint>
#include <vector>

class MultiplexerOne
{
private:

	int64_t packet_to_send = 0;
	int64_t packet_to_receive = 0;

	int64_t all_packets = 0;
	int64_t all_lost_packets = 0;
	//int64_t PLR = 0;

	const int64_t buffer_size = 40000; // packets
	
public:


	int64_t frame_to_packets(std::vector<int64_t>* frames);
	void write_in_buffer();
	void read_frome_buffer();

	int64_t get_packet_to_send() { return packet_to_send; }
	int64_t get_packet_to_receive() { return packet_to_receive; };
	int64_t get_all_packets() { return all_packets; }
	int64_t get_lost_packets() { return all_lost_packets; }
	
	void set_packet_to_send(int64_t new_frame_packets) { packet_to_send += new_frame_packets; }
	void set_packet_to_receive(int64_t value) { packet_to_receive += value; }
};