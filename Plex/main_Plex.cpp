#include "Plex.h"

using namespace std;

int main()
{
  std::cout << "An example of working with Plex."
    << std::endl << "Denisov Vladislav L. Group 381706-1\n" << std::endl;
  
  cout << "Enter the coordinates of 1 point separated by a space: ";
  double x1, y1; 
  cin >> x1 >> y1;
  cout << "Enter the coordinates of 1 point separated by a space: ";
  double x2, y2;
  cin >> x2 >> y2;
  cout << "Enter the coordinates of 1 point separated by a space: ";
  double x3, y3;
  cin >> x3 >> y3;
  cout << endl;

  cout << "Built Plex 'plex' using 'point1' and 'point2'\n";
  TPoint point1(x1, y1), point2(x2, y2), point3(x3, y3);
  TPlex plex(&point1, &point2);
  plex.Show();
  cout << endl;
  
  cout << "Added line 'point2' and 'point3' to the previous 'plex'\n";
  plex.Add(&point2, &point3);
  plex.Show();

  return 0;
}