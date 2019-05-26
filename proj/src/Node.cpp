#include "Node.h"

Node::Node():Node(0,0,0) {}

Node::Node(int id, double x, double y):id(id),x(x),y(y) {}

Node::Node(int id):id(id) {}

void Node::setX(double x)
{
	this->x = x;
}

void Node::setY(double y)
{
	this->y = y;
}

void Node::setId(int id)
{
	this->id = id;
}

double Node::getX()
{
	return x;
}

double Node::getY()
{
	return y;
}

int Node::getId()
{
	return id;
}

bool Node::operator==(const Node & n) const
{
	return id == n.id;
}

bool Node::operator!=(const Node & n) const
{
	return !this->operator==(n);
}

ostream & operator<<(ostream & os, const Node & n)
{
	os << "{ID: " << n.id << ", x: " << n.x << ", y: " << n.x << "}";
	return os;
}



