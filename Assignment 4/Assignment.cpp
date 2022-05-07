#include <iostream>

using namespace std;

struct Contact{
    string name;
    string phoneNumber;
    Contact *left;
    Contact *right;
};

class ContactBook{
    private:
        int countName = 0;
        Contact* root;

        void insertContact(Contact *&tree,string name, string phoneNumber){
            if(tree == NULL){
                tree = new Contact;
                tree->name = name;
                tree->phoneNumber = phoneNumber;
                tree->left = NULL;
                tree->right = NULL;
            }else if(phoneNumber < tree->phoneNumber){
                insertContact(tree->left, name, phoneNumber);
            }else{
                insertContact(tree->right, name, phoneNumber);
            }
        }

        void printInOrder(Contact *tree){
            if(tree == NULL){
                return;
            }
            printInOrder(tree->left);
            cout << tree->name << ", " << tree->phoneNumber << endl;
            printInOrder(tree->right);
        }

        void printAllName(Contact *tree, string name){
            if(tree == NULL){
                return;
            }
            printAllName(tree->left, name);
            if(tree->name == name){
                cout << tree->name << ", " << tree->phoneNumber << endl;
            }
            printAllName(tree->right, name);
        }

        int treeLength(Contact *tree){
            if(tree==NULL){
                return 0;
            }
            return 1+treeLength(tree->left)+treeLength(tree->right);
        }

        bool findContact(Contact *tree, string phoneNumber){
            if(tree==NULL){
                return false;
            }

            if(tree->phoneNumber == phoneNumber){
                return true;
            }
            else if(phoneNumber < tree->phoneNumber){
                return findContact(tree->left, phoneNumber);
            }
            else{
                return findContact(tree->right, phoneNumber);
            }
        }

        Contact* retrieveContact(Contact *tree, string phoneNumber){
            if(tree==NULL){
                return NULL;
            }

            if(tree->phoneNumber == phoneNumber){
                return tree;
            }
            else if(phoneNumber < tree->phoneNumber){
                return retrieveContact(tree->left,phoneNumber);
            }
            else{
                return retrieveContact(tree->right,phoneNumber);
            }
        }


        bool retrieveContactN(Contact *tree, string name){
            if(tree==NULL){
                return false;
            }

            retrieveContactN(tree->left,name);
            if((tree->name).find(name) != -1){
                cout << tree->name << ", " << tree->phoneNumber << endl;
            }
            retrieveContactN(tree->right,name);
        }

        bool retrieveContactBool (Contact *tree, string name){
            if(tree==NULL){
                return false;
                countName = 0;
            }

            retrieveContactBool(tree->left,name);
            if((tree->name).find(name) != -1){
                countName++;
            }
            retrieveContactBool(tree->right,name);
        }

        void deleteContact(Contact *&tree, string phoneNumber){
            if(tree == NULL){
                return;
            }
            if(tree->phoneNumber == phoneNumber){
                if(tree->left == NULL && tree->right == NULL){
                    delete tree;
                    tree = NULL;
                }
                else if(tree->left != NULL){
                    string maxLeftContact = findMaxContact(tree->left);
                    string maxLeftName = findMaxContactName(tree->left);
                    tree->phoneNumber = maxLeftContact;
                    tree->name = maxLeftName;
                    deleteContact(tree->left,maxLeftContact);
                }
                else{
                    string minRightContact = findMinContact(tree->right);
                    string minRightName = findMaxContactName(tree->right);
                    tree->phoneNumber = minRightContact;
                    tree->name = minRightName;
                    deleteContact(tree->right,minRightContact);
                }
            }
            else if(tree->phoneNumber < phoneNumber){
                deleteContact(tree->right,phoneNumber);
            }
            else{
                deleteContact(tree->left,phoneNumber);
            }
        }

        void deleteAllContacts(Contact *tree){
            if(tree == NULL){
                return;
            }
            deleteAllContacts(tree->left);
            deleteAllContacts(tree->right);
            delete tree;
        }

        void rootNull(){
            root = NULL;
        }

        string findMinContact(Contact *tree){
            if(tree == NULL){
                return NULL;
            }else if(tree->left == NULL){
                return tree->phoneNumber;
            }else{
                return findMinContact(tree->left);
            }
        }

        string findMaxContact(Contact *tree){
            if(tree == NULL){
                return NULL;
            }else if(tree->right == NULL){
                return tree->phoneNumber;
            }else{
                return findMaxContact(tree->right);
            }
        }

        string findMaxContactName(Contact *tree){
            if(tree == NULL){
                return NULL;
            }else if(tree->right == NULL){
                return tree->name;
            }else{
                return findMaxContactName(tree->right);
            }
        }

        void makeEmpty(Contact *&tree){
            if(tree == NULL){
                return;
            }
            makeEmpty(tree->left);
            makeEmpty(tree->right);
            delete tree;
            tree = NULL;
        }

        int getHeight(Contact *tree){
            if(tree == NULL){
                return 0;
            }
            int lsh = 1+getHeight(tree->left);
            int rsh = 1+getHeight(tree->right);

            if(lsh > rsh){
                return lsh;
            }else{
                return rsh;
            }
        }

        int countContacts(Contact *tree){
            if(tree==NULL){
                return 0;
            }
            return 1+countContacts(tree->left)+countContacts(tree->right);
        }


    public:

        ContactBook(){
            root = NULL;
        }
        void insertContact(string name, string phoneNumber){
            insertContact(root, name, phoneNumber);
        }

        void printInOrder(){
            printInOrder(root);
        }

        void printAllName(string name){
            printAllName(root, name);
        }

        int treeLength(){
            treeLength(root);
        }

        Contact* retrieveContact(string phoneNumber){
            return retrieveContact(root,phoneNumber);
        }

        bool retrieveContactN(string name){
            return retrieveContactN(root,name);
        }

        bool retrieveContactBool (string name){
            return retrieveContactBool(root,name);
        }

        bool findContact(string phoneNumber){
            findContact(root,phoneNumber);
        }

        void deleteContact(string phoneNumber){
            deleteContact(root,phoneNumber);
        }

        void deleteAllContacts(){
            deleteAllContacts(root);
        }

        void makeNull(){
            rootNull();
        }

        string findMinContact(){
            findMinContact(root);
        }
        string findMaxContact(){
            findMaxContact(root);
        }

        bool isBalanced();

        void makeEmpty(){
            makeEmpty(root);
        }

        int getHeight(){
            getHeight(root);
        }

        bool isEmpty(){
            if(root == NULL){
                return true;
            }else{
                return false;
            }
        }

        int countContacts(){
            return countContacts(root);
        }

        void menu(){
            int choice;
            string name;
            string phoneNo;
            char exit;
            
            while(true){
                cout << "********************\n"
                        "*** CONTACT BOOK ***\n"
                        """********************\n"
                        "\n"
                        "------ Menu --------\n"
                        "1. View all contacts\n"
                        "2. Add new contact\n"
                        "3. Search a contact by name\n"
                        "4. Search a contact by phone number\n"
                        "5. Delete a contact\n"
                        "6. Delete all contacts\n"
                        "7. Exit program\n"
                        "--------------------\n"
                        "Select an option (1-7): ";

                cin >> choice;
                cout << "--------------------\n" << endl;

                switch(choice){
                    case 1:
                        if(isEmpty()){
                            cout << "*** View Contacts ***\n" << endl;
                            cout << "Contact Book is empty.\n" << endl;
                        }
                        else{
                            cout << "*** View Contacts ***\n" << endl;
                            cout << "Showing " << countContacts() << " contacts:\n" << endl;
                            printInOrder();
                            cout << endl;
                        }
                    break;
                    
                    case 2:
                        cout << "> Enter name: ";
                        cin.ignore();
                        getline(cin, name);

                        cout << "> Enter phone number: ";
                        cin >> phoneNo;

                        if(findContact(phoneNo) == true){
                            cout << "\nError: A contact with phone number "<< phoneNo <<" already exists.\n" << endl;
                            break;
                        }
                        else{
                            insertContact(name, phoneNo);
                            cout << "\nContact added successfully\n" << endl;
                        }

                    break;

                    case 3:
                        cout << "\n*** Search Contact By Name ***\n" << endl;
                        cout << "> Enter name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << endl;

                        if(retrieveContactBool(name) == false){
                            cout << "Contact not found." << endl;
                        }
                        
                        cout << countName << " contacts found: \n" << endl;
                        retrieveContactN(name);

                        cout << endl;
                        
                    break;

                    case 4:
                        cout << "*** Search Contact By Phone Number ***\n" << endl;
                        cout << "> Enter phone number: ";
                        cin >> phoneNo;

                        if(retrieveContact(phoneNo) == NULL){
                            cout << "\nContact not found.\n" << endl;
                        }
                        else{
                            Contact *info = retrieveContact(phoneNo);
                            cout << "\nContact found:\n" << endl;
                            cout << info->name << ", " << info->phoneNumber << endl;
                        }

                        cout << endl;

                    break;

                    case 5:
                        cout << "*** Delete Contact ***\n" << endl;
                        cout << "> Enter phone number: ";
                        cin >> phoneNo;

                        if(retrieveContact(phoneNo) == NULL){
                            cout << "\nContact not found.\n" << endl;
                        }
                        else{
                            char opt;

                            cout << "\nDelete this contact? Enter y for yes, n for no: ";
                            cin>> opt;

                            if(opt == 'y' || opt == 'Y'){
                                deleteContact(phoneNo);
                                cout << "\nContact deleted successfully.\n" << endl;
                            }
                        }

                    break;

                    case 6:
                        char opt;

                        cout << "*** Delete All Contacts ***\n" << endl;
                        cout << "Are you sure? Enter y for yes, n for no: ";
                        cin >> opt;

                        if(opt == 'y' || opt == 'Y'){
                            deleteAllContacts();
                            makeNull();
                            cout << "\nAll contacts deleted.\n" << endl;
                        }
                        else if(opt == 'n' || opt == 'N'){
                            cout << endl;
                        }

                    break;

                    case 7:
                        cout << "> Are you sure? Enter y for yes, n for no: ";
                        cin >> exit;

                        if(exit == 'y' || exit == 'Y'){
                            cout << "\n*** Thank you for using Contact Book ***" << endl;
                            return;
                        }
                    break;

                    default:
                        cout << "\nError!\n" << endl;
                    break;
                }
            }
        }
};



int main(){
    ContactBook p;
    
    p.menu();   

return 0;
}