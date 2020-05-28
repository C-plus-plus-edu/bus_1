#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void add_bus_list(vector<string>& bus_list, string new_bus) {
	bus_list.push_back(new_bus);
}

void new_bus(map<string, vector<string>>& buses, vector<string>& bus_list) {
	vector<string> new_counts;
	string new_bus;
	int z;
	cin >> new_bus >> z;
	add_bus_list(bus_list, new_bus);
	for (int i = 0; i < z; ++i) {
		string new_stops;
		cin >> new_stops;
		new_counts.push_back(new_stops);
	}
	buses[new_bus] = new_counts;
}

bool check_bus(vector<string>& buses_stops, string stop_name) {
	for (auto x : buses_stops) {
		if (x == stop_name) {
			return true;
		}
	}
	return false;
}

void buses_for_stop(map<string, vector<string>>& buses, vector<string>& bus_list) {
	bool c = false;
	string stop_name;
	cin >> stop_name;
	for (auto x : bus_list) {
		if (check_bus(buses[x], stop_name) == true) {
			c = true;
			cout << x << " ";
		}
	}
	if (c == false) {
		cout << "No stop";
	}
	cout << endl;
}

void stops_for_bus(map<string, vector<string>>& buses, vector<string>& bus_list) {
	bool c;
	string bus_name;
	cin >> bus_name;
	if (buses[bus_name].size() == 0) {
		cout << "No bus" << endl;
		buses.erase(bus_name);
	} else {
		for (auto x : buses[bus_name]) {
			c = false;
			cout << "Stop " << x << ": ";
			for (auto y : bus_list) {
				if (y != bus_name) {
					if (check_bus(buses[y], x) == true) {
						c = true;
						cout << y << " ";
					}
				}
			}
			if (c == false) {
				cout << "no interchange";
			}
			cout << endl;
		}
	}
}

void all_buses(map<string, vector<string>>& buses) {
	if (buses.size() == 0) {
		cout << "No buses" << endl;
	} else {
		for (auto x : buses) {
			cout << "Bus " << x.first << ": ";
			for (auto y : x.second) {
				cout << y << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	map<string, vector<string>> buses;
	vector<string> bus_list;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string cmd;
		cin >> cmd;
		if (cmd == "NEW_BUS") {
			new_bus(buses, bus_list);
		} else if (cmd == "BUSES_FOR_STOP") {
			buses_for_stop(buses, bus_list);
		} else if (cmd == "STOPS_FOR_BUS") {
			stops_for_bus(buses, bus_list);
		} else if (cmd == "ALL_BUSES") {
			all_buses(buses);
		}
	}
	return 0;
}
