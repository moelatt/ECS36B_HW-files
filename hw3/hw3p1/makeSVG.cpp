// Moe Ko Latt
// ID: 915866164
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void header(){
	cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>"<< endl
		 << "<svg width=\"700\" height=\"600\"" << endl
		 << "xmlns=\"http://www.w3.org/2000/svg\">" << endl
		 << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl 
		 << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl
		 << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>" << endl;
}
void footer() {
	cout << "</g>" << endl;
  	cout << "</svg>" << endl;
}
int main()
{
	int x, y, width, height, r;
	char ch ;
	header();
	cin >> ch ;
	while(cin)
	{
	if(ch == 'R'){
	cin >> x >> y >> width >> height;
	cout << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\"/>" << endl;
	}
	else if(ch == 'C'){
		cin >> x >> y >> r;
		cout << "<circle cx=\""<< x << "\" cy=\"" << y << "\" r=\"" << r << "\"/>" << endl;
	}
	else{
		return 0;
	}
	cin >> ch;
	}
	footer();
	return 0;
}






