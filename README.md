for more details, you can read the following paper: Characterization of effective bandwidth as a metric of quality of service for wired and wireless ATM networks Abbas MohammadiSurinder KumarDavid Klymyshyn IEEE International Conference on Communications (1997) 
DOI: 10.1109/icc.1997.610034

In the following, I will elaborate on what I did for this project.

This project addresses the statistical multiplexing characteristics of aggregated video traffic stream.  For this purpose, you will be provided with three empirical traces of MPEG video frame sizes.  Your task is to write a simple simulation program of a video multiplexer to produce the results requested in this question.  You may write your simulation in the language of your choice.  
The video multiplexer in your simulation has N input ports, each fed by a different video traffic stream arriving on a link of 45 Mbps transmission capacity.  The multiplexer has a single output port, with link capacity C bps.  At the output port there is buffer of size B cells to store IP Packets waiting to enter the network.

The multiplexer operates as follows.  Each video traffic stream generates and deposits a new video frame into the buffer at a fixed frame rate of 25 frames per second (i.e., a new frame is deposited into the buffer every 40 milliseconds).  For the purpose of simulation, assume that all the packets of the frame arrive back to back at the incoming link rate, and that they have been converted into IP packets from 80 bytes to 120 bytes of frame data (and 20 bytes of IP header) per packet.  Packets that do not fit into the (finite) buffer at the time of packet arrival must be discarded.

The output port has a capacity C, which controls the departure rate of packets from the buffer.  That is, if the outgoing rate is r packets per second, then the packets (if any) waiting in the buffer depart in a deterministic fashion with on packet every 1/r  seconds.  In this fashion, occasional backlogs of packets may build up and dissipate during the course of simulation, depending on the frame sizes generated in in the video traffic stream.  The only performance metric of interests is the packet loss ratio (PLR) at the multiplexers output buffer.

You will be provided with three different video traffic data sets for the simulation.  Each data set is an empirical time series representing the frame sizes (in bits) of each video frame in an MPEG movie.  Each trace contains 40,000 frames (about 27 minutes of video).  

For each individual input video sequence(i.e. N=1), you are to conduct a simulation experiment that determines the impact of the multiplexer buffer size B (in Byte) and the outgoing link capacity C (in bits per second) on the PLR experienced by the video traffic.  Use your own judgment to determine what values of B and C to use. Please use at least three levels for each factors. The results from your simulation should be plotted on a graph that shows the PLR on the vertical axis (on a logarithmic scale), and the outgoing link capacity C on the horizontal axis.  Draw one line on the graph for each buffer size B used in this experiment.  You should produce one such graph for each of the three video traffic sources.  

Next, you should simulate all three traffic sources at once (i.e.N=3), with the sources statistically multiplexed onto the output link (i.e. sharing the fixed size output buffer).  Use this configuration to assess the impact of B and C on the overall PLR  for the aggregated traffic streams.  Make sure to stagger the relative start times of the video streams so that their first frame are not all in synchronization with each other(e.g. suggested phasing shift of 150 milliseconds for each source).  Produce a graph as before to show the simulation results.

Finally, you should obtain the effective bandwidth for individual sources and aggregated traffic using the self similar model and compare your simulation results with the effective bandwidth estimation. Produce graphs for this comparison. 

Note:  You may estimate Hurst parameter by yourself or you may use the following values:

Traffic Characteristics of Various Video Traffic Sources
Video	Mean[Mbps]	Var-Parameter[b-s]	Hurst
Jurassic Park	.327	4.93E-4	.85
Silence of the Lamps	.183	6.48E-4	.90
StarWars	.233	7.25E-4	.85



