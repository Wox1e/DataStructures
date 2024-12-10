#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
	T value;
	Node* previous = nullptr;
	Node* next = nullptr;
public:
	Node(T value, Node* previous, Node* next)
	{
		this->value = value;
		this->previous = previous;
		this->next = next;
		previous->next = this;
		next->previous = this;
	}
	Node(T value, Node* previous)
	{
		this->value = value;
		this->previous = previous;
		this->next = nullptr;
		previous->next = this;
	}
	Node(T value)
	{
		this->value = value;
		this->previous = nullptr;
		this->next = nullptr;
	}

	Node* getPrevious()
	{
		return this->previous;
	}
	Node* getNext()
	{
		return this->next;
	}
	T getValue()
	{
		return this->value;
	}
	void setValue(T value)
	{
		this->value = value;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	void setPrevious(Node* previous)
	{
		this->previous = previous;
	}


};



template <typename T>
class LinkedList
{
private:
	Node<T>* begin = nullptr;
	Node<T>* end = nullptr;
public:
	LinkedList() {};
	LinkedList(initializer_list<T> l)
	{
		for (T element : l)
		{
			this->push_back(element);
		}
	}
	~LinkedList()
	{
		Node<T>* currentNode = this->begin;

		while (currentNode != nullptr)
		{
			//cout << currentNode->getValue() <<" || " << currentNode <<" deleted" << "\n";
			Node<T>* nextNode = currentNode->getNext();
			delete currentNode;
			currentNode = nextNode;
		}

	}
	void push_back(T value)
	{
		Node<T>* node = new Node<T>(value);
		if (this->end != nullptr)
		{
			this->end->setNext(node);
			node->setPrevious(this->end);
			this->end = node;
			return;
		}
		this->begin = node;
		this->end = node;
	}
	void push_front(T value)
	{
		Node<T>* node = new Node<T>(value);

		if (this->begin != nullptr)
		{
			Node<T>* currentBegin = this->begin;
			currentBegin->setPrevious(node);
			node->setNext(currentBegin);
			this->begin = node;
			return;
		}

		this->begin = node;
		this->end = node;

	}
	Node<T>* get_begin()
	{
		return this->begin;
	}
	Node<T>* get_end()
	{
		return this->end;
	}
	T pop_back()
	{
		if (this->end == nullptr)
		{
			exception e("Error. Empty list");
			throw e;
		}

		if (this->begin == this->end)
		{
			int value = this->end->getValue();
			delete this->end;
			this->end = nullptr;
			this->begin = nullptr;
			return value;
		}

		Node<T>* currentEnd = this->end;
		Node<T>* newEnd = currentEnd->getPrevious();


		int value = currentEnd->getValue();
		newEnd->setNext(nullptr);
		this->end = newEnd;
		delete currentEnd;
		return value;
	}
	T pop_front()
	{
		if (this->begin == nullptr)
		{
			exception e("Error. Empty list");
			throw e;
		}

		if (this->begin == this->end)
		{
			int value = this->end->getValue();
			delete this->end;
			this->end = nullptr;
			this->begin = nullptr;
			return value;
		}

		Node<T>* currentBegin = this->begin;
		Node<T>* newBegin = currentBegin->getNext();

		int value = currentBegin->getValue();
		newBegin->setPrevious(nullptr);
		this->begin = newBegin;
		delete currentBegin;
		return value;
	}
	void insert(T value, int index)
	{
		if (index == 0)
		{
			this->push_front(value);
			return;
		}

		int current_position = 0;
		Node<T>* current_node = this->begin;

		while (current_position != index and current_node != nullptr)
		{
			current_node = current_node->getNext();
			current_position++;
		}


		if (index > current_position)
		{
			exception e("Error. Outside the list");
			throw e;
		}

		if (current_node == nullptr)
		{
			this->push_back(value);
			return;
		}

		Node<T>* node = new Node<T>(value);
		current_node->getPrevious()->setNext(node);
		node->setPrevious(current_node->getPrevious());
		current_node->setPrevious(node);
		node->setNext(current_node);

	}
	void remove(int index)
	{
		if (this->begin == nullptr)
		{
			exception e("Empty list");
			throw e;
		}

		if (index == 0)
		{
			Node<T>* new_begin = this->begin->getNext();
			delete begin;
			this->begin = new_begin;
			this->begin->setPrevious(nullptr);
			return;
		}

		int current_position = 0;
		Node<T>* current_node = this->begin;

		while (current_position != index and current_node != nullptr)
		{
			current_node = current_node->getNext();
			current_position++;
		}


		if (index > current_position)
		{
			exception e("Error. Outside the list");
			throw e;
		}

		if (current_node == this->begin)
		{
			Node<T>* prev = current_node->getPrevious();
			prev->setNext(nullptr);
			this->end = prev;
			delete current_node;
			return;
		}

		Node<T>* prev = current_node->getPrevious();
		Node<T>* next = current_node->getNext();

		prev->setNext(next);
		next->setPrevious(prev);
		delete current_node;
	}

	friend ostream& operator << (ostream& os, LinkedList<T>& list)
	{
		Node<T>* current = list.get_begin();
		while (current != nullptr)
		{
			os << current->getValue() << " ";
			current = current->getNext();
		}
		return os;
	}

	T front()
	{
		return this->begin->getValue();
	}
	T back()
	{
		return this->end->getValue();
	}
	bool empty()
	{
		return this->begin == this->end;
	}
	int size()
	{
		int size = 0;
		Node<T>* currentNode = begin;
		while (currentNode != nullptr)
		{
			currentNode = currentNode->getNext();
			size++;
		}
		return size;

	}
	void clear()
	{
		Node<T>* currentNode = this->begin;

		while (currentNode != nullptr)
		{
			Node<T>* nextNode = currentNode->getNext();
			delete currentNode;
			currentNode = nextNode;
		}
		this->begin = nullptr;
		this->end = nullptr;
	}
	bool operator==(LinkedList<T>& other)
	{
		if (this->size() != other.size())
		{
			return false;
		}

		Node<T>* currentNode_this = this->begin;
		Node<T>* currentNode_other = other.begin;

		while (currentNode_this != nullptr)
		{
			if (currentNode_this->getValue() != currentNode_other->getValue())
			{
				return false;
			}
			currentNode_other = currentNode_other->getNext();
			currentNode_this = currentNode_this->getNext();
		}

		return true;
	}
	void operator=(initializer_list<T> l)
	{
		this->clear();
		for (T element : l)
		{
			this->push_back(element);
		}
	}
};
