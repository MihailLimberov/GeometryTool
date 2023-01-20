/**
*
* Solution to course project # 03 - GeometryTool
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Mihail Limberov
* @idnumber 6MI0600176
* @compiler VC
*
* <Works with different elements of the coordinate system>
*
*/

#include <iostream>
#include <cmath>
using namespace std;

void DefinePoints(string(&points)[100], double(&point_x_coordinate)[100], double(&point_y_coordinate)[100], int& pointCounter, string& operation)
{
	cout << "Enter 'point' or 'stop': ";
	cin >> operation;
	while (operation != "stop")
	{
		if (operation == "point")
		{
			cout << "Enter name for the point: ";
			cin >> points[pointCounter];
			cout << "Enter a x coordinate for a point: ";
			cin >> point_x_coordinate[pointCounter];
			cout << "Enter a y coordinate for a point: ";
			cin >> point_y_coordinate[pointCounter];

			pointCounter++;
		}

		cout << "Enter 'point' or 'stop': ";
		cin >> operation;
	}
}
void DefineLines(string(&lines)[100], double(&line_a_coefficient)[100], double(&line_b_coefficient)[100], double(&line_c_coefficient)[100], int& lineCounter, string& operation)
{
	cout << "Enter 'line' or 'stop': ";
	cin >> operation;
	while (operation != "stop")
	{
		if (operation == "line")
		{
			cout << "Enter name for the line: ";
			cin >> lines[lineCounter];
			cout << "Enter 'a' coefficient before variable 'x': ";
			cin >> line_a_coefficient[lineCounter];
			cout << "Enter 'b' coefficient before variable 'y': ";
			cin >> line_b_coefficient[lineCounter];
			cout << "Enter constant 'c': ";
			cin >> line_c_coefficient[lineCounter];

			lineCounter++;
		}

		cout << "Enter 'line' or 'stop': ";
		cin >> operation;
	}
}
void PrintPoints(string(&points)[100], double(&point_x_coordinate)[100], double(&point_y_coordinate)[100], int& pointCounter)
{
	for (int i = 0; i < pointCounter; i++)
	{
		cout << "point: " << points[i] << "(" << point_x_coordinate[i] << ";" << point_y_coordinate[i] << ")" << endl;
	}
}
void PrintLines(string(&lines)[100], double(&line_a_coefficient)[100], double(&line_b_coefficient)[100], double(&line_c_coefficient)[100], int& lineCounter)
{
	for (int i = 0; i < lineCounter; i++)
	{
		if (line_b_coefficient[i] < 0 && line_c_coefficient[i] < 0)
		{
			cout << "line: " << lines[i] << ": " << line_a_coefficient[i] << "x  " << line_b_coefficient[i] << "y  " << line_c_coefficient[i] << " = 0" << endl;
		}
		else if (line_b_coefficient[i] < 0)
		{
			cout << "line: " << lines[i] << ": " << line_a_coefficient[i] << "x  " << line_b_coefficient[i] << "y + " << line_c_coefficient[i] << " = 0" << endl;
		}
		else if (line_c_coefficient[i] < 0)
		{
			cout << "line: " << lines[i] << ": " << line_a_coefficient[i] << "x + " << line_b_coefficient[i] << "y  " << line_c_coefficient[i] << " = 0" << endl;
		}

		else cout << "line: " << lines[i] << ": " << line_a_coefficient[i] << "x + " << line_b_coefficient[i] << "y + " << line_c_coefficient[i] << " = 0" << endl;
	}
}
void PointIsOnLine(double(&line_a_coefficient)[100], double(&line_b_coefficient)[100], double(&line_c_coefficient)[100], double(&point_x_coordinate)[100], double(&point_y_coordinate)[100])
{
	if (line_a_coefficient[0] * point_x_coordinate[0] + line_b_coefficient[0] * point_y_coordinate[0] + line_c_coefficient[0] == 0)
	{
		cout << "The point is on the line." << endl;
	}
	else cout << "the point is not on the line" << endl;
}
void PointAndParallelLine(double(&line_a_coefficient)[100], double(&line_b_coefficient)[100], double(&line_c_coefficient)[100], double(&point_x_coordinate)[100], double(&point_y_coordinate)[100])
{
	double pointC = (-1) * line_b_coefficient[0] * point_y_coordinate[0] - line_a_coefficient[0] * point_x_coordinate[0];
	cout << "The parallel line intersecting the given point is: ";
	if (line_b_coefficient[0] > 0 && pointC > 0)
	{
		cout << line_a_coefficient[0] << "x + " << line_b_coefficient[0] << "y + " << pointC << " = 0" << std::endl;
	}
	else if (line_b_coefficient[0] > 0 && pointC < 0)
	{
		cout << line_a_coefficient[0] << "x + " << line_b_coefficient[0] << "y " << pointC << " = 0" << std::endl;
	}
	else if (line_b_coefficient[0] < 0 && pointC > 0)
	{
		cout << line_a_coefficient[0] << "x " << line_b_coefficient[0] << "y +" << pointC << " = 0" << std::endl;
	}
	else cout << line_a_coefficient[0] << "x " << line_b_coefficient[0] << "y " << pointC << " = 0" << std::endl;
}
void PerpendicularLineAndPoint(double(&line_a_coefficient)[100], double(&line_b_coefficient)[100], double(&line_c_coefficient)[100], double(&point_x_coordinate)[100], double(&point_y_coordinate)[100])
{
	if (line_a_coefficient[0] * point_x_coordinate[0] + line_b_coefficient[0] * point_y_coordinate[0] + line_c_coefficient[0] == 0)
	{
		double pointC = line_a_coefficient[0] * point_y_coordinate[0] - line_b_coefficient[0] * point_x_coordinate[0];

		cout << "The perpendicular line at the given point is: ";
		if ((-1) * line_a_coefficient[0] > 0 && pointC > 0)
		{
			cout << line_b_coefficient[0] << "x + " << (-1) * line_a_coefficient[0] << "y + " << pointC << " = 0" << endl;
		}
		else if ((-1) * line_a_coefficient[0] > 0 && pointC < 0)
		{
			cout << line_b_coefficient[0] << "x + " << (-1) * line_a_coefficient[0] << "y " << pointC << " = 0" << endl;
		}
		else if ((-1) * line_a_coefficient[0] < 0 && pointC > 0)
		{
			cout << line_b_coefficient[0] << "x " << (-1) * line_a_coefficient[0] << "y + " << pointC << " = 0" << endl;
		}
		else cout << line_b_coefficient[0] << "x " << (-1) * line_a_coefficient[0] << "y " << pointC << " = 0" << endl;
	}
	else cout << "The point is not on the line!" << endl;
}
void TwoLinesIntersection(double(&line_a_coefficient)[100], double(&line_b_coefficient)[100], double(&line_c_coefficient)[100])
{
	if (line_a_coefficient[0] / line_a_coefficient[1] == line_b_coefficient[0] / line_b_coefficient[1])
	{
		cout << "The lines are paralell or are aligned" << endl;
	}
	else
	{
		double pointX1 = (line_b_coefficient[0] * line_c_coefficient[1] - line_b_coefficient[1] * line_c_coefficient[0]) / (line_a_coefficient[0] * line_b_coefficient[1] - line_a_coefficient[1] * line_b_coefficient[0]);
		double pointY1 = (line_a_coefficient[1] * line_c_coefficient[0] - line_a_coefficient[0] * line_c_coefficient[1]) / (line_a_coefficient[0] * line_b_coefficient[1] - line_a_coefficient[1] * line_b_coefficient[0]);

		cout << "The intersection point is: ";
		cout << "(" << pointX1 << ";" << pointY1 << ")" << endl;
	}
}
void TriangleSpecificLines(double(&point_x_coordinate)[100], double(&point_y_coordinate)[100])
{
	double x1 = point_x_coordinate[0];
	double y1 = point_y_coordinate[0];

	double x2 = point_x_coordinate[1];
	double y2 = point_y_coordinate[1];

	double x3 = point_x_coordinate[2];
	double y3 = point_y_coordinate[2];

	double height1const = y3 * (y2 - y1) + x3 * (x2 - x1);
	double height2const = y1 * (y3 - y2) + x1 * (x3 - x2);
	double height3const = y2 * (y1 - y3) + x2 * (x1 - x3);

	double P_x1x2Center = (x1 + x2) / 2;
	double Q_x2x3Center = (x2 + x3) / 2;
	double S_x1x3Center = (x1 + x3) / 2;

	double P_y1y2Center = (y1 + y2) / 2;
	double Q_y2y3Center = (y2 + y3) / 2;
	double S_y1y3Center = (y1 + y3) / 2;



	cout << "Equations of heights: " << endl;
	cout << "line: " << x1 - x2 << "x + (" << y1 - y2 << ")y + (" << height1const << ") = 0" << endl;
	cout << "line: " << x2 - x3 << "x + (" << y2 - y3 << ")y + (" << height2const << ") = 0" << endl;
	cout << "line: " << x3 - x1 << "x + (" << y3 - y1 << ")y + (" << height3const << ") = 0" << endl;
	cout << "Equations of medians: " << endl;
	cout << "line: " << P_y1y2Center - y3 << "x + (" << x3 - P_x1x2Center << ")y + (" << y3 * P_x1x2Center - x3 * P_y1y2Center << ") = 0" << endl;
	cout << "line: " << Q_y2y3Center - y1 << "x + (" << x1 - Q_x2x3Center << ")y + (" << y1 * Q_x2x3Center - x1 * Q_y2y3Center << ") = 0" << endl;
	cout << "line: " << S_y1y3Center - y2 << "x + (" << x2 - S_x1x3Center << ")y + (" << y2 * S_x1x3Center - x2 * S_y1y3Center << ") = 0" << endl;
	cout << "Equations of simetrals: " << endl;
	cout << "line: " << x1 - x2 << "x + (" << y1 - y2 << ")y + (" << P_y1y2Center * (y2 - y1) + P_x1x2Center * (x2 - x1) << ") = 0" << endl;
	cout << "line: " << x2 - x3 << "x + (" << y2 - y3 << ")y + (" << Q_y2y3Center * (y3 - y2) + Q_x2x3Center * (x3 - x2) << ") = 0" << endl;
	cout << "line: " << x3 - x1 << "x + (" << y3 - y1 << ")y + (" << S_y1y3Center * (y1 - y3) + S_x1x3Center * (x1 - x3) << ") = 0" << endl;
}
void TangentInGivenPoint(double(&point_x_coordinate)[100], double(&point_y_coordinate)[100], double& aCoeff, double& bCoeff, double& cCoeff)
{
	double derivativePoint = 2 * aCoeff * point_x_coordinate[0] + bCoeff;

	cout << "Eqation of the tangent is: " << endl;
	cout << derivativePoint << "x - y +(" << derivativePoint * point_x_coordinate[0] + point_y_coordinate[0] << ") = 0" << endl;
}
void IntersectionPointQadraticLine(double& aCoeff, double& bCoeff, double& cCoeff, double(&line_a_coefficient)[100], double(&line_b_coefficient)[100], double(&line_c_coefficient)[100])
{
	double a = aCoeff * line_b_coefficient[0];
	double b = bCoeff * line_b_coefficient[0] + line_a_coefficient[0];
	double c = line_c_coefficient[0] + cCoeff * line_b_coefficient[0];
	double x1;
	double x2;
	double y1;
	double y2;
	double d = b * b - 4 * a * c;

	if (d < 0)
	{
		cout << "No intersection points." << endl;
	}
	else
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		y1 = ((-1) * line_a_coefficient[0] * x1 - line_c_coefficient[0]) / (line_b_coefficient[0]);
		y2 = ((-1) * line_a_coefficient[0] * x2 - line_c_coefficient[0]) / (line_b_coefficient[0]);
		cout << "Intersection points: (" << x1 << ";" << y1 << ")  ,  (" << x2 << ";" << y2 << ")" << endl;
	}

}
void QadraleteralIdentifier(double(&line_a_coefficient)[100], double(&line_b_coefficient)[100], double(&line_c_coefficient)[100])
{
	if (line_a_coefficient[0]/line_a_coefficient[1] == line_b_coefficient[0]/line_b_coefficient[1] && line_a_coefficient[1] / line_a_coefficient[2] == line_b_coefficient[1] / line_b_coefficient[2])
	{
		cout << "Not a Qadraliteral!" << endl;
	}
	else if (line_a_coefficient[1] / line_a_coefficient[2] == line_b_coefficient[1] / line_b_coefficient[2] && line_a_coefficient[2] / line_a_coefficient[3] == line_b_coefficient[2] / line_b_coefficient[3])
	{
		cout << "Not a Qadraliteral!" << endl;
	}
	else if (line_a_coefficient[0] / line_a_coefficient[2] == line_b_coefficient[0] / line_b_coefficient[2] && line_a_coefficient[2] / line_a_coefficient[3] == line_b_coefficient[2] / line_b_coefficient[3])
	{
		cout << "Not a Qadraliteral!" << endl;
	}
	else
	{
		cout << "Concave or convex quadrilateral" << endl;
	}
	
}
void DeletePointsAndLines(int& pointCounter, int& lineCounter)
{
	pointCounter = 0;
	lineCounter = 0;
}
int main()
{
	string operation;

	string lines[100];
	string points[100];

	double line_a_coefficient[100];
	double line_b_coefficient[100];
	double line_c_coefficient[100];

	double point_x_coordinate[100];
	double point_y_coordinate[100];

	double aCoeff;
	double bCoeff;
	double cCoeff;

	int pointCounter = 0;
	int lineCounter = 0;


	cout << "1 - Define and print points." << endl;
	cout << "2 - Define and print lines." << endl;
	cout << "3 - Check if point is on a line." << endl;
	cout << "4 - Build parallel line by given another line and point" << endl;
	cout << "5 - Build perpendicular line by given point on the line" << endl;
	cout << "6 - Intersection point of two lines" << endl;
	cout << "7 - Lines of heights, medians and simetrals of triangle" << endl;
	cout << "8 - Tangent to quadratic equation in given point" << endl;
	cout << "9 - Intersection points of quadratic equation and line" << endl;
	cout << "10 - Quadraleteral Identifier" << endl;
	cout << endl;
	cout << "Enter a number from 1 to 10 for operation: ";
	cin >> operation;
	cout << endl;

	while (operation != "exit")
	{

		if (operation == "1")
		{
			DefinePoints(points, point_x_coordinate, point_y_coordinate, pointCounter, operation);
			PrintPoints(points, point_x_coordinate, point_y_coordinate, pointCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;

		}
		else if (operation == "2")
		{
			DefineLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter, operation);
			PrintLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;
		}
		else if (operation == "3")
		{
			cout << "Enter one line: " << endl;
			DefineLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter, operation);
			cout << "Enter one point:" << endl;
			DefinePoints(points, point_x_coordinate, point_y_coordinate, pointCounter, operation);

			PrintPoints(points, point_x_coordinate, point_y_coordinate, pointCounter);
			PrintLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter);
			PointIsOnLine(line_a_coefficient, line_b_coefficient, line_c_coefficient, point_x_coordinate, point_y_coordinate);

			DeletePointsAndLines(pointCounter, lineCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;

		}
		else if (operation == "4")
		{
			cout << "Enter one line: " << endl;
			DefineLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter, operation);
			cout << "Enter one point:" << endl;
			DefinePoints(points, point_x_coordinate, point_y_coordinate, pointCounter, operation);

			PrintPoints(points, point_x_coordinate, point_y_coordinate, pointCounter);
			PrintLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter);
			PointAndParallelLine(line_a_coefficient, line_b_coefficient, line_c_coefficient, point_x_coordinate, point_y_coordinate);

			DeletePointsAndLines(pointCounter, lineCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;
		}
		else if (operation == "5")
		{
			cout << "Enter one line: " << endl;
			DefineLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter, operation);
			cout << "Enter one point on the chosen line:" << endl;
			DefinePoints(points, point_x_coordinate, point_y_coordinate, pointCounter, operation);

			PrintPoints(points, point_x_coordinate, point_y_coordinate, pointCounter);
			PrintLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter);
			PerpendicularLineAndPoint(line_a_coefficient, line_b_coefficient, line_c_coefficient, point_x_coordinate, point_y_coordinate);

			DeletePointsAndLines(pointCounter, lineCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;
		}
		else if (operation == "6")
		{
			cout << "Enter two lines: " << endl;
			DefineLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter, operation);

			PrintLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter);
			TwoLinesIntersection(line_a_coefficient, line_b_coefficient, line_c_coefficient);

			DeletePointsAndLines(pointCounter, lineCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;
		}
		else if (operation == "7")
		{
			cout << "Enter 3 points (not on one line):" << endl;
			DefinePoints(points, point_x_coordinate, point_y_coordinate, pointCounter, operation);

			PrintPoints(points, point_x_coordinate, point_y_coordinate, pointCounter);
			TriangleSpecificLines(point_x_coordinate, point_y_coordinate);

			DeletePointsAndLines(pointCounter, lineCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;
		}
		else if (operation == "8")
		{
			cout << "Enter coefficents of the quadratic equation 'ax^2 + bx + c = y   (a != 0)'" << endl;
			cout << "a = ";
			cin >> aCoeff;
			cout << "b = ";
			cin >> bCoeff;
			cout << "c = ";
			cin >> cCoeff;
			cout << "Enter one point on the quadratic equation: " << std::endl;
			DefinePoints(points, point_x_coordinate, point_y_coordinate, pointCounter, operation);
			PrintPoints(points, point_x_coordinate, point_y_coordinate, pointCounter);
			cout << "Quadratic equation: y = " << aCoeff << "x^2 +(" << bCoeff << ")x + (" << cCoeff << ")" << endl;
			TangentInGivenPoint(point_x_coordinate, point_y_coordinate, aCoeff, bCoeff, cCoeff);

			DeletePointsAndLines(pointCounter, lineCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;
		}
		else if (operation == "9")
		{
			cout << "Enter coefficents of the quadratic equation 'ax^2 + bx + c = y'  (a != 0)" << endl;
			cout << "a = ";
			cin >> aCoeff;
			cout << "b = ";
			cin >> bCoeff;
			cout << "c = ";
			cin >> cCoeff;
			cout << "Enter one line:" << endl;
			DefineLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter, operation);
			cout << "Quadratic equation: y = " << aCoeff << "x^2 +(" << bCoeff << ")x + (" << cCoeff << ")" << endl;
			PrintLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter);
			IntersectionPointQadraticLine(aCoeff, bCoeff, cCoeff, line_a_coefficient, line_b_coefficient, line_c_coefficient);

			DeletePointsAndLines(pointCounter, lineCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;
		}
		else if (operation == "10")
		{
			cout << "Enter 4 lines:" << endl;
			DefineLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter, operation);
			PrintLines(lines, line_a_coefficient, line_b_coefficient, line_c_coefficient, lineCounter);
			QadraleteralIdentifier(line_a_coefficient, line_b_coefficient, line_c_coefficient);

			DeletePointsAndLines(pointCounter, lineCounter);
			cout << "Enter an operation from 1 to 10 or write 'exit' to close the program: ";
			cin >> operation;
			if (operation == "exit") return 0;
		}

		else return 0;

	}

}


