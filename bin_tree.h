class BinarySearchTree {
private:
    // внутренний класс для узла дерева
    class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // вспомогательный метод для добавления узла
    Node* addNode(Node* node, int data) {
        if (node == nullptr) {
            node = new Node(data);
        }
        else if (data < node->data) {
            node->left = addNode(node->left, data);
        }
        else if (data > node->data) {
            node->right = addNode(node->right, data);
        }
        return node;
    }

    // вспомогательный метод для поиска узла
    Node* searchNode(Node* node, int data) {
        if (node == nullptr || node->data == data) {
            return node;
        }
        else if (data < node->data) {
            return searchNode(node->left, data);
        }
        else {
            return searchNode(node->right, data);
        }
    }

    // вспомогательный метод для удаления узла
    Node* deleteNode(Node* node, int data) {
        if (node == nullptr) {
            return node;
        }
        else if (data < node->data) {
            node->left = deleteNode(node->left, data);
        }
        else if (data > node->data) {
            node->right = deleteNode(node->right, data);
        }
        else {
            // узел найден
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // вспомогательный метод для поиска узла с минимальным значением в поддереве
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // вспомогательный метод для вывода узла в виде дерева
    void printNode(Node* node, int indent) {
        if (node == nullptr) {
            return;
        }
        std::cout << std::string(indent, ' ') << node->data << std::endl;
        if (node->left != nullptr || node->right != nullptr) {
            std::cout << std::string(indent, ' ') << "|\n";
        }
        printNode(node->left, indent + 4);
        if (node->left != nullptr && node->right != nullptr) {
            std::cout << std::string(indent, ' ') << "|\n";
        }
        printNode(node->right, indent + 4);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // метод для добавления узла
    void add(int data) {
        root = addNode(root, data);
    }

    // метод для поиска узла
    Node* search(int data) {
        return searchNode(root, data);
    }

    // метод для удаления узла
    void remove(int data) {
        root = deleteNode(root, data);
    }

    // метод для вывода дерева в консоль
    void print() {
        printNode(root, 0);
    }
};
