// Binary tree
class Node
{
public:
	Node(int value) { this->value = value;}
	Node(Node* right, Node* left) {
		this->right = right;
		this->left = left;
	}
	bool operator > (const Node& another_node)
	{
		return this->value > another_node.value;
	}
	bool operator < (const Node& another_node)
	{
		return this->value < another_node.value;
	}
	bool operator == (const Node& another_node)
	{
		return this->value == another_node.value;
	}
	Node* get_right()
	{
		return this->right;
	}
	Node* get_left()
	{
		return this->left;
	}
	void set_right(Node* right) {
		this->right = right;
	}
	void set_left(Node* left)
	{
		this->left = left;
	}
	int get_value()
	{
		return this->value;
	}

private:
	Node* right = nullptr;
	Node* left = nullptr;
	int value;
};



class BinaryTree
{
public:
	BinaryTree(int value)
	{
		this->root = new Node(value); // delete
	}

	BinaryTree(Node* root)
	{
		this->root = root;
	}

	BinaryTree() = default;

	void push_back(int value)
	{
		Node* new_node = new Node(value);
		Node* current_node = this->root;

		while (current_node != nullptr)
		{
			if (current_node == new_node)
			{
				//std::cerr << "Already in tree\n";
				return;
			}
			if (new_node > current_node)
			{
				if (current_node->get_right() != nullptr)
				{
					current_node = current_node->get_right();
				}
				else
				{
					current_node->set_right(new_node);
					return;
				}
				
			}
			else
			{
				if (current_node->get_left() != nullptr)
				{
					current_node = current_node->get_left();
				}
				else
				{
					current_node->set_left(new_node);
					return;
				}
			}
		}


		
	}
	bool contains(int value)
	{
		Node* current_node = this->root;
		while (current_node != nullptr)
		{
			if (current_node->get_value() == value) return true;
			if (value > current_node->get_value()) current_node = current_node->get_right();
			else current_node = current_node->get_left();
		}
		return false;

	}



private:
	Node* root = nullptr;
};

