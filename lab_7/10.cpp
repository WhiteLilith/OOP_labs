class Polar

{

private:
	double x;
	double y;

	double radius;
	double angle;

public:

	Polar()
	{
		x = 0;
		y = 0;
		radius = 0;
		angle = 0;
	}

	Polar(float rad, float ang)
	{
		x = rad * cos(ang);
		y = rad * sin(ang);
		radius = rad;
		angle = ang;
	}

	Polar operator+(Polar a)
	{
		double NewX = a.x + x;
		double NewY = a.y + y;
		double NewRadius = sqrt(NewX * NewX + NewY * NewY);
		double NewAngle = acos(NewX / NewRadius);
		Polar rez(NewRadius, NewAngle);
		return rez;
	}

	void GetCoordinates()
	{
		cout << "Radius = " << radius << ", Angle = " << angle << endl;
	}

};

////////////////////////////////////////////////////////////////

int main()
{

	Polar first(24, 2.23);
	cout << "First: ";
	first.GetCoordinates();

	Polar second(2.036, 6.65);
	cout << "Second: ";
	second.GetCoordinates();

	Polar result = first + second;

	cout << "Result of summation: ";
	result.GetCoordinates();

	return 0;
}
