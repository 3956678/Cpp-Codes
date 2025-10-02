#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Create tree
Node* create() {
    int x;
    cout << "Enter data (-1 for NULL): ";
    cin >> x;
    if (x == -1) return nullptr;

    Node* node = new Node(x);
    cout << "Left child of " << x << ":\n";
    node->left = create();
    cout << "Right child of " << x << ":\n";
    node->right = create();
    return node;
}

// Arrays to hold path
int tempLeft[100], tempRight[100], finalPath[100];

// Main function to calculate height and track diameter path
int getHeight(Node* node, int path[], int& pathLen, int& maxDiameter, int final[]) {
    if (node == nullptr) return 0;

    int leftLen = 0, rightLen = 0;
    int lh = getHeight(node->left, tempLeft, leftLen, maxDiameter, final);
    int rh = getHeight(node->right, tempRight, rightLen, maxDiameter, final);

    // Check if this node gives a bigger diameter
    if (lh + rh + 1 > maxDiameter) {
        maxDiameter = lh + rh + 1;
        int index = 0;
        // Left path (reverse order)
        for (int i = leftLen - 1; i >= 0; i--)
            final[index++] = tempLeft[i];
        // Current node
        final[index++] = node->data;
        // Right path
        for (int i = 0; i < rightLen; i++)
            final[index++] = tempRight[i];
        pathLen = index;
    }

    // Return deeper side path
    if (lh > rh) {
        for (int i = 0; i < leftLen; i++)
            path[i] = tempLeft[i];
        path[leftLen] = node->data;
        pathLen = leftLen + 1;
    } else {
        for (int i = 0; i < rightLen; i++)
            path[i] = tempRight[i];
        path[rightLen] = node->data;
        pathLen = rightLen + 1;
    }

    return max(lh, rh) + 1;
}

int main() {
    Node* root = create();

    int diameter = 0;
    int pathLen = 0;

    getHeight(root, finalPath, pathLen, diameter, finalPath);

    cout << "\nDiameter (no. of edges): " << diameter - 1 << endl;
    cout << "Diameter Path: ";
    for (int i = 0; i < pathLen; i++)
        cout << finalPath[i] << " ";
    cout << endl;

    return 0;
}
