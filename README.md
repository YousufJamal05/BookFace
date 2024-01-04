The primary objective of the BookFace project is to illustrate the implementation of core social media features in a console environment. 
This undertaking serves as an educational endeavour to comprehend data structures, user interaction methods, and file-handling techniques in C++.

Project Structure
-------------------------
Main Program
•	The main program handles the user interface and navigation through the system.
•	Users can log in, sign up, view their profile, add friends, and perform other activities.
•	Utilizes functions from the header files for various functionalities.
Header Files
•	Contains classes for Users, Posts, Comments, Replies, NewsFeed, UserGraph, and Updates.
•	Manages user data, connections, posts, comments, and system updates.
•	Implements core functionalities like adding friends, posting updates, and displaying content.
Frontend Header File
•	Provides functions for console-based UI elements and user input/output.
•	Offers functionalities for drawing UI boxes, getting user input securely, and displaying content.
Execution and Flow
•	The program begins with the main menu, prompting users to log in, sign up, or exit.
•	User authentication and account creation are handled through the UserGraph class.
•	Once logged in, users navigate the system via the main menu, performing actions like posting updates, commenting, and managing connections.
•	The NewsFeed class manages posts, comments, and replies, displaying relevant content to users.

DATA STRUCTURES
-----------------
1. Linked List
•	Usage: Efficient storage and management of user-generated content such as updates, comments, and replies.
•	Functionality: Facilitates sequential storage and traversal of dynamic content within the simulated social platform.
2,Queue
Usage:
•	Storage: Manages messages or notifications in a FIFO manner.
•	Functionality: Simulates handling incoming messages or user notifications within the platform.
Usage in Simulation:
•	Emulating the management of user messages or notifications.
3. Graph (UserGraph)
•	Usage: Representation of user connections and relationships within the simulated social network.
•	Functionality: Tracks friendships, manages connections, and simulates user interactions within the platform.


Details of Data Structures
-------------------------------
Linked List
•	Usage:
•	Storage: Stores updates, comments, and replies in a structured manner.
•	Functionality: Allows for efficient management and traversal of user-generated content.
•	Usage in Simulation:
•	Node* front, *rear: Linked list nodes for storing updates within the simulated social platform.
•	Comment* comments, Reply* replies: Linked list structure for comments and replies in the simulation.
Queue
•	Usage:
•	Storage: Manages messages or notifications in a FIFO manner.
•	Functionality: Simulates handling incoming messages or user notifications within the platform.
•	Usage in Simulation:
•	Emulating the management of user messages or notifications.
Graph (UserGraph)
•	Usage:
•	Storage: Represents user connections and relationships.
•	Functionality: Simulates managing friendships, connections, and interactions within the social network.
•	Usage in Simulation:
•	vector< vector<bool>> connections: Simulates friendships between users within the simulated platform.



Data Structures Analysis:
------------------------------
•	Efficient Content Management:
•	Linked lists enable dynamic content management, ensuring structured handling of updates and interactions.
•	Social Connectivity Simulation:
•	The 2D array (connections matrix) and graph representation (UserGraph) simulate social relationships and user connections efficiently.
Efficiency Considerations:
•	Linked List Insertion:
•	Linked lists facilitate O(1) insertion, ideal for managing sequential updates and comments.
•	Graph Representation:
•	The connections matrix and graph structure provide efficient ways to represent and manage user relationships.
