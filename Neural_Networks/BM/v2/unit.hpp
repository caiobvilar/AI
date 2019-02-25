#ifndef _UNIT_HPP_
#define _UNIT_HPP_


class Unit
{
	private:
		int id;
		int state;
		bool visibility;
	public:
		int getID();
		void setID(int id_in);
		int getState();
		void setState(int st);
		bool getVisibility();
		void setVisibility(bool visible);
};

class Connection
{
	private:
		int unit_1;
		int unit_2;
		double weight;
	public:
		void setConnection(int id1,int id2);
		int getID1();
		int getID2();
		double getWeight();
		void setWeight(double w);
};

//TODO:
//+
//+
//+
//+
//
//
#endif //_UNIT_HPP_
