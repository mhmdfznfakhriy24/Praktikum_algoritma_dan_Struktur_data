#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

Node* buatNode(int item)
{
    Node *n = new Node;
    n->data = item;
    n->kiri = NULL;
    n->kanan = NULL;
    return n;
}

Node* insert(Node *root, int data)
{
    if (root == NULL)
        return buatNode(data);

    if (data < root->data)
        root->kiri = insert(root->kiri, data);
    else if (data > root->data)
        root->kanan = insert(root->kanan, data);

    return root;
}

int diameter = 0;

int height(Node *root)
{
    if (root == NULL)
        return -1; // -1 supaya leaf punya height 0

    int leftHeight = height(root->kiri);
    int rightHeight = height(root->kanan);

    // update diameter (jarak = leftHeight + rightHeight + 2)
    int jarak = leftHeight + rightHeight + 2;
    if (jarak > diameter)
        diameter = jarak;

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    int n;
    cin >> n;

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    height(root);
    cout << diameter << endl;

    return 0;
}