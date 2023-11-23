#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

typedef struct
{
    char name[20];
    char gender[10];
    char dateOfAdmission[20];
    char dateOfBirth [20];
    char Illness[20];
    char address [15];
    char bloodType[5];

} str;
struct Node
{
    struct Node *left;
    struct Node *right;
    int height;
    str data;
};
typedef struct hash
{
    char status[5];//E empty , O Occupied , D deleted
    str data;
} Hash;
int getBalance(struct Node *N);
struct Node *leftRotate(struct Node *x);
struct Node* newNode(str data);
struct Node *rightRotate(struct Node *y);
struct Node* insert(struct Node* node, str data);
void readFile(str s[],FILE *in);
int height(struct Node *N);
struct Node *leftRotate(struct Node *x);
int max(int a, int b);
void preOrder(struct Node *root);
void inOrder(struct Node *root);
void insertIntoDataStruct(str s[]);
struct Node *findIlness(struct Node *root,char illness[] );
struct Node* findPatient(struct Node *root,char name[]);
void insertNewPatient(struct Node *node);
void update(struct Node *index);
struct Node* makeEmpety(struct Node *node);
int isEmpety(struct Node *root);
struct Node *findMin(struct Node *node);
struct Node *deletion(struct Node *node,char name[]);
void saveFile(FILE *out,struct Node *root);
int keyValue(char word[]);
int prime(int n);
void hashInsert(str data,Hash *array );
void init_array(Hash array[]);
void deletionHash(Hash array[],char key[],int tableSize);
void printAll(Hash array[]);
void findHash(Hash array[],char key[],int tableSize);
Hash *rehash(Hash *a);
double loadFactor(double n,double size);
str insertNewHash(Hash array[]);
void insertFromFile(str s[],Hash array[]);
void saveHash(FILE *out,Hash array[]);
void ReadFromAvlToHash(struct Node *node,Hash array []);
void hashMenu();
void avlMenu();
void continuee();

struct Node *Avl=NULL;

Hash *Array=NULL;

int check=0;

//number of nodes in hash array
int number=0;

//initialize table size by 5
//when load factor > 0.5 ... size=size*2 (RE HASH START)
int size=5;

//to check if update done
int up=0;

int main()
{
    char w;
    int time=0;
    str s[300],k[300];
    FILE *in,*out;
    in=fopen("patients.txt","r");
    out=fopen("patients_hash.data","w");
    char string[300];
    int operation=0;
    puts("____________-------------   AVL MENU   -------------____________\n");

    while(operation!=7)
    {
        avlMenu();

        scanf("%d",&operation);
        switch(operation)
        {
        case 1:
        {
            if(time==0)
            {
                readFile( s, in);
                insertIntoDataStruct( s);
                time++;
            }
            puts("\nOperation Number 1 Done\n");
            continuee();

            break;
        }
        case 2 :
        {

            insertNewPatient(Avl);
            puts("\nOperation Number 2 Done\n");
            continuee();

            break;
        }
        case 3:
        {
            printf("please enter the Patient name that u want to find it:- ");

            scanf("%c",&w);
            scanf("%[^\n]",string);
            struct Node *x= findPatient(Avl,string);
            if(x!=NULL)
            {
                puts("\nThe Patient did u look for it is :- \n");
                printf("\nName: %s, gender:  %s, dateOfAdmission:  %s, dateOfBirth:  %s, Illness:  %s, address:  %s, bloodType:  %s,\n\n", x->data.name,x->data.gender,x->data.dateOfAdmission,x->data.dateOfBirth,x->data.Illness,x->data.address,x->data.bloodType);

                update(x);
            }


            puts("\nOperation Number 3 Done\n");
            continuee();

            break;
        }
        case 4:
        {
            if(Avl==NULL)
            {
                printf("\nThe tree is empty\n")  ;
            }
            else
            {
                printf("\n lexicographic for patient name From A To z :\n");
                inOrder(Avl);

            }
            puts("\nOperation Number 4 Done\n");
            continuee();

            break;
        }
        case 5:
        {
            printf("please enter the Ilness name that u want to find it:- \n");
            scanf("%c",&w);
            scanf("%[^\n]",string);

            printf("\n The list of patients that have that illness are :-\n\n");
            findIlness(Avl, string);
            if(check==0)
            {
                printf("\n(.....There is no patients have that ilness name.....) \n\n");
            }
            check=0;

            puts("\nOperation Number 5 Done\n");
            continuee();

            break;
        }
        case 6:
        {
            printf("please enter the Patient name that u want to delete it:- \n");
            scanf("%c",&w);
            scanf("%[^\n]",string);
            Avl= deletion(Avl,string);
            puts("\nOperation Number 6 Done\n");
            continuee();

            break;
        }
        case 7:
        {
            fprintf(out,"WORDS FROM AVL PART:-\n");
            saveFile(out,Avl);
            Array=(Hash*)malloc(size*sizeof(Hash));
            init_array( Array);
            char n[300];
            if(isEmpety(Avl))
            {
                puts("\nThe tree was Empty ... the hash will fill from input file\n");
                readFile( k, in);
                insertFromFile(k,Array);
            }
            ReadFromAvlToHash(Avl,Array);

            puts("\nOperation Number 7 Done\n");
            continuee();

            puts("\n............................................................................................\n");
            puts("____________-------------   HASH MENU   -------------____________\n");

            while( 1)
            {
                hashMenu();

                scanf("%d",&operation);

                switch(operation)
                {
                case 1:
                {
                    puts("");
                    printAll(Array);
                    puts("");
                    puts("||| operation number 1 done |||\n");
                    continuee();


                    break;
                }
                case 2:
                {
                    puts("");

                    printf("THE TABLE SIZE = %d\n",size);
                    printf("The number of keys in the table = %d\n\n",number);
                    puts("||| operation number 2 done |||\n");
                    continuee();


                    puts("");
                    break;
                }
                case 3:
                {
                    puts("");
                    puts("The Hash function type used is : -Open Addressing- ((Quadratic Probing)) \n");
                    puts("The function used is : \n\nhi(key) = [h(key) + i^2] % tableSize ,h(key) = key % tableSize\n");
                    puts("");
                    puts("||| operation number 3 done |||\n");
                    continuee();


                    break;
                }
                case 4 :
                {
                    puts("");
                    puts("insert:-");
                    str data;
                    data=insertNewHash(Array);
                    hashInsert(data,Array);
                    if(loadFactor(number,size)>=0.5)
                    {
                        number=0;
                        Array=rehash(Array);
                    }
                    puts("");
                    puts("||| operation number 4 done |||\n");
                    continuee();


                    break;
                }
                case 5:
                {
                    puts("");
                    puts("Enter the patient name that u want search it :-");
                    scanf("%c",&w);
                    scanf("%[^\n]",n);
                    puts("");
                    findHash(Array,n,size);
                    puts("");
                    puts("||| operation number 5 done |||\n");
                    continuee();


                    break;
                }
                case 6:
                {
                    puts("");
                    puts("Enter the patient name that u want delete it it :-");
                    scanf("%c",&w);
                    scanf("%[^\n]",n);
                    deletionHash(Array,n,size);
                    puts("");
                    puts("||| operation number 6 done |||\n");
                    continuee();


                    break;
                }
                case 7:
                {
                    fprintf(out,"\nWORDS FROM HASH PART:-\n");

                    saveHash(out, Array);
                    fclose(out);


                    fclose(out);
                    puts("||| operation number 7 done |||\n");
                    continuee();

                    break;

                }
                case 8:
                {
                    printf("\nEXIT DONE...\n");
                    fclose(out);
                    exit(0);
                    break;
                }
                default:
                {
                    puts("Wrong number ... Try Again\n");
                }
                }
                puts("----------------------------------------------------------------------------------------------------\n");
            }
            break;
        }
        case 8:
        {
            printf("\nEXIT DONE...\n");
            fclose(out);
            exit(0);
            break;
        }

        default:
        {
            puts("Wrong number ... Try Again\n");
        }
        }
        puts("----------------------------------------------------------------------------------------------------\n");

    }

}

//*************************************************************************************************************

//-------------------------------------------------------------------------------------------------------------

//*************************************************************************************************************


//HASH

//Hash menu
void hashMenu()
{
    puts("Choose the number of operation u want :)\n");
    puts("1-Print hashed table");
    puts("2-Print out table size");
    puts("3-Print out the used hash function");
    puts("4-Insert a new record into the hash table.");
    puts("5-Search for a specific patient");
    puts("6-Delete a specific record");
    puts("7-Save hash table back to file");
    puts("8-CLOSE THE FILE AND EXIT FROM SYSTEM");
}
//function to re hash when load factor > 0.7
Hash *rehash(Hash *a)
{

    int newSize=prime(2*size);
    int oldSize=size;
    size=newSize;
    Hash *copy;
    copy=(Hash*)malloc(newSize* sizeof(Hash));
    int i=0;

    for( i=0; i<newSize; i++)
    {

        strcpy(copy[i].status,"E");
        strcpy(copy[i].data.name,"EMPTY");

    }
    for( i=0; i<oldSize; i++)
    {
        if(strcmp(a[i].status,"O")==0)
        {
            hashInsert(a[i].data,copy);
        }
    }
    free(a);
    return copy;


}
//get the sum of ASCII for the string
int keyValue(char word[])
{
    int i=0;
    int value=0;
    while ( word[i] !='\0')
    {
        value += word[i];
        i++;
    }
    return value;


}
//return the load factor
double loadFactor(double n,double size)
{
    double load ;
    load=(double)((double)n/(double)size);
    return load;
}
//return the prime number
int prime(int n)
{
    int i=0;
    if(n==0)
    {
        return 2;
    }
    for (i = 2; i <= n / 2; ++i)
    {

        if (n % i == 0)
        {
            {
                n++;
                i=2;
            }

        }
    }

    return n;

}
//initialize the array status and name
void init_array(Hash array[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        strcpy(array[i].status,"E");
        strcpy(array[i].data.name,"EMPTY");
    }
}
//return the key value
int hashValue(char key[],int i)
{
    int value=((keyValue(key)%size)+(i*i))%size;
    return value;
}
//insert a new node into the hash array
void hashInsert(str data,Hash *array )
{
    int i=0;

    int index=hashValue(data.name,i);
    if(strcmp(array[index].status,"E")==0||strcmp(array[index].status,"D")==0)
    {

        strcpy( array[index].status,"O");
        strcpy(array[index].data.name,data.name);
        strcpy(array[index].data.Illness,data.Illness);
        strcpy(array[index].data.dateOfAdmission,data.dateOfAdmission);
        strcpy(array[index].data.dateOfBirth,data.dateOfBirth);
        strcpy(array[index].data.gender,data.gender);
        strcpy(array[index].data.address,data.address);
        strcpy(array[index].data.bloodType,data.bloodType);

        number++;

    }
    else if( (strcmp(array[index].status,"O")==0)&&strcmp(array[index].data.name,data.name)!=0)
    {
        while(strcmp(array[index].status,"O")==0)
        {
            if(strcmp(array[index].data.name,data.name)==0)
            {
                printf("\nSorry,this key name (%s) is already Exist ,we cant add it ,\n",data.name);
                break;
            }
            index=hashValue(data.name,i++);
        }
        strcpy( array[index].status,"O");
        strcpy(array[index].data.name,data.name);
        strcpy(array[index].data.Illness,data.Illness);
        strcpy(array[index].data.dateOfAdmission,data.dateOfAdmission);
        strcpy(array[index].data.dateOfBirth,data.dateOfBirth);
        strcpy(array[index].data.gender,data.gender);
        strcpy(array[index].data.address,data.address);
        strcpy(array[index].data.bloodType,data.bloodType);
        number++;

    }
    else
    {
        printf("\nSorry,this key name (%s) is already Exist ,we cant add it ,\n",data.name);

    }

}
//search a patient which index is exist
void findHash(Hash array[],char key[],int tableSize)
{
    int i=0;
    int index= hashValue( key, i);
    if(strcmp(array[index].status,"E")==0)
    {
        printf("\nThe Key not Found\n");
    }
    else //if(array[index].status==1,2)
    {
        while(strcmp(array[index].status,"O")==0&&strcmp(array[index].data.name,key)!=0)
        {
            i++;
            index= hashValue(  key, i);
        }
        if(strcmp(array[index].data.name,key)==0)
        {
            printf("The Key %s is Exist at index %d \n",array[index].data.name,index);
            printf("\nThe data for him are:- \n\n");
            printf("index: %d  status:  %s  name: %s  gender: %s  dateOfAdmission: %s  dateOfBirth: %s  Illness: %s  address: %s  bloodType: %s\n",index,array[index].status,array[index].data.name,array[index].data.gender,array[index].data.dateOfAdmission,array[index].data.dateOfBirth,array[index].data.Illness,array[index].data.address,array[index].data.bloodType);


        }
        else
        {
            printf("The Key %s is not Exist \n",key);
        }
    }


}
//deletion a patent by setting its data to empty and status E
void deletionHash(Hash array[],char key[],int tableSize)
{
    int i=0;
    int index= hashValue(  key, i);
    if(strcmp(array[index].status,"E")==0)
    {
        printf("The Key not Found\n");
    }
    else //if(array[index].status==O,D)
    {
        while((strcmp(array[index].status,"O")==0||strcmp(array[index].status,"O")==0)&&strcmp(array[index].data.name,key)!=0)
        {
            i++;
            index= hashValue(  key, i);
        }
        if(strcmp(array[index].data.name,key)==0)
        {
            strcpy(array[index].status,"D");

            strcpy(array[index].data.name,"EMPTY");

            number--;

        }
        else
        {
            printf("The Key %s is not Exist \n",key);
        }
    }

}
//print hash array
void printAll(Hash array[])
{

    for(int j=0; j<size; j++)
    {
        if(strcmp(array[j].data.name,"EMPTY")==0)
        {
            if(j<=9)
                printf("index:  %d  status:  %s  data: EMPTY\n",j,array[j].status);
            else
                printf("index: %d  status:  %s  data: EMPTY\n",j,array[j].status);

        }
        else
        {
            if(j<=9)
                printf("index:  %d  status:  %s  name: %s  gender: %s  dateOfAdmission: %s  dateOfBirth: %s  Illness: %s  address: %s  bloodType: %s\n",j,array[j].status,array[j].data.name,array[j].data.gender,array[j].data.dateOfAdmission,array[j].data.dateOfBirth,array[j].data.Illness,array[j].data.address,array[j].data.bloodType);
            else
                printf("index: %d  status:  %s  name: %s  gender: %s  dateOfAdmission: %s  dateOfBirth: %s  Illness: %s  address: %s  bloodType: %s\n",j,array[j].status,array[j].data.name,array[j].data.gender,array[j].data.dateOfAdmission,array[j].data.dateOfBirth,array[j].data.Illness,array[j].data.address,array[j].data.bloodType);

        }
    }
}
//ask a questions about patient to insert him
str insertNewHash(Hash array[])
{
    char c;
    str data;
    char New[300];
    printf("Enter the name of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.name,New);

    printf("Enter the gender of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.gender,New);

    printf("Enter the Date of admission of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.dateOfAdmission,New);
    printf("Enter the Date of Birth of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.dateOfBirth,New);
    printf("Enter the Illness of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.Illness,New);
    printf("Enter the Address of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.address,New);
    printf("Enter the Blood type of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.bloodType,New);
    return data;
}
//insert the data from the file
void insertFromFile(str s[],Hash array[])
{
    int i=0;
    str data;
    while(s[i].name[0]!='\0')
    {
        strcpy(data.name,s[i].name);
        strcpy(data.address,s[i].address);
        strcpy(data.bloodType,s[i].bloodType);
        strcpy(data.dateOfBirth,s[i].dateOfBirth);
        strcpy(data.dateOfAdmission,s[i].dateOfAdmission);
        strcpy(data.gender,s[i].gender);
        strcpy(data.Illness,s[i].Illness);
        hashInsert(data,Array);
        if(loadFactor(number,size)>=0.5)
        {
            number=0;
            Array=rehash(Array);
        }
        i++;


    }
}
//save data after operations at output file
void saveHash(FILE *out,Hash array[])
{
    for(int j=0; j<size; j++)
    {
        if(strcmp(array[j].data.name,"EMPTY")!=0)
        {

            fprintf(out,"name: %s  gender: %s  dateOfAdmission: %s  dateOfBirth: %s  Illness: %s  address: %s  bloodType: %s\n",array[j].data.name,array[j].data.gender,array[j].data.dateOfAdmission,array[j].data.dateOfBirth,array[j].data.Illness,array[j].data.address,array[j].data.bloodType);

        }
    }

}
void ReadFromAvlToHash(struct Node *node,Hash array [])
{
    str data;
    if(node != NULL)
    {
        ReadFromAvlToHash(node->left,array);
        strcpy(data.name,node->data.name);
        strcpy(data.address,node->data.address);
        strcpy(data.bloodType,node->data.bloodType);
        strcpy(data.dateOfBirth,node->data.dateOfBirth);
        strcpy(data.dateOfAdmission,node->data.dateOfAdmission);
        strcpy(data.gender,node->data.gender);
        strcpy(data.Illness,node->data.Illness);
        hashInsert(data,Array);
        if(loadFactor(number,size)>=0.5)
        {
            number=0;
            Array=rehash(Array);
        }
        ReadFromAvlToHash(node->right,array);

    }
}

//*************************************************************************************************************

//-------------------------------------------------------------------------------------------------------------

//*************************************************************************************************************


//AVL

// avl menu
void avlMenu()
{
    puts("Enter the number of operation u want perform :)\n");
    puts("1-Read the file patients.txt and load the data (i.e., AVL Tree)");
    puts("2-Insert a new patient from user with all its associated data");
    puts("3-Find a patient and give the user the option to update the information of the patient if found");
    puts("4-List all patients in lexicographic order with their associated information");
    puts("5-List all patients that have the same illness.");
    puts("6-Delete a patient from the system");
    puts("7-Save all words in file \"patients_hash.data\",and go to (( HASH MENU ))");
    puts("8-EXIT FROM SYSTEM");
}
////save data after operations at output file
void saveFile(FILE *out,struct Node *root)
{

    if(root != NULL)
    {

        saveFile(out,root->left);
        fprintf(out,"name: %s  gender: %s  dateOfAdmission: %s  dateOfBirth: %s  Illness: %s  address: %s  bloodType: %s\n", root->data.name,root->data.gender,root->data.dateOfAdmission,root->data.dateOfBirth,root->data.Illness,root->data.address,root->data.bloodType);

        saveFile(out,root->right);

    }

}
//delete node from the tree
struct Node *deletion(struct Node *node,char name[])
{
    if(isEmpety(node))
    {
        printf("\nThe node not found\n");
    }
    else if(strcmp(node->data.name,name)>0)
    {
        node->left=deletion(node->left,name);
    }
    else if(strcmp(node->data.name,name)<0)
    {
        node->right=deletion(node->right,name);
    }
    else
    {

        if(node->left==NULL&&node->right==NULL)
        {

            free(node);
            node=NULL;

        }
        else if(node->left==NULL&&node->right!=NULL)
        {
            struct Node *temp=node;
            node=node->right;
            free(temp);



        }
        else if(node->left!=NULL&&node->right==NULL)
        {
            struct Node *temp=node;
            node=node->left;
            free(temp);
        }
        else
        {

            struct Node *min=findMin(node->right);
            node->data=min->data;
            node->right=deletion(node->right,min->data.name) ;

        }
    }
    if (node == NULL)
        return node;

    node->height = 1 + max(height(node->left),height(node->right));

    // check whether this node became unbalanced)
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
//insert new node at the tree
void insertNewPatient(struct Node *node)
{
    char c;
    str data;
    char New[300];
    printf("Enter the name of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.name,New);
    printf("Enter the gender of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.gender,New);
    printf("Enter the Date of admission of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.dateOfAdmission,New);
    printf("Enter the Date of Birth of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.dateOfBirth,New);
    printf("Enter the Illness of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.Illness,New);
    printf("Enter the Address of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.address,New);
    printf("Enter the Blood type of Patient :-\n ");
    scanf("%c",&c);
    scanf("%[^\n]",New);
    strcpy(data.bloodType,New);
    Avl= insert(Avl,data);
}
//update the data for a patient
void update(struct Node *index)
{
    int x=0;
    str data=index->data;
    char New[30];
    int op=0;
    char temp;
    while(op!=8)
    {
        printf("\nchoose the number of data u want to update... choose 8 to Exit :-\n\n");
        puts("1-update the name \n");
        puts("2-update the Gender\n");
        puts("3-update the Date of admission\n");
        puts("4-update the Date of birth  \n");
        puts("5-update the Illness\n");
        puts("6-update the Address\n");
        puts("7-update the Blood type \n");
        puts("8-Exit\n");
        scanf("%d",&op);
        switch(op)
        {


        case 1:
        {

            x++;
            printf("Enter the new name :-        note :- if u change the name for name is already in the tree ... your operation will not performed\n");

            scanf("%c",&temp);
            scanf("%[^\n]",New);

            strcpy(data.name,New);

            break;
        }

        case 2:
        {
            printf("Enter the new Gender :-\n");
            scanf("%c",&temp);
            scanf("%[^\n]",New);

            strcpy(data.gender,New);
            x++;
            break;
        }


        case 3:
        {
            x++;
            printf("Enter the new Date of admission :-\n");
            scanf("%c",&temp);
            scanf("%[^\n]",New);

            strcpy(data.dateOfAdmission,New);
            break;
        }


        case 4:
        {
            x++;
            printf("Enter the new Date of birth :-\n");
            scanf("%c",&temp);
            scanf("%[^\n]",New);

            strcpy(data.dateOfBirth,New);
            break;
        }


        case 5:
        {
            x++;
            printf("Enter the new Illness :-\n");
            scanf("%c",&temp);
            scanf("%[^\n]",New);

            strcpy(data.Illness,New);
            break;
        }


        case 6:
        {
            x++;
            printf("Enter the new Address :-\n");
            scanf("%c",&temp);
            scanf("%[^\n]",New);

            strcpy(data.address,New);
            break;
        }


        case 7:
        {
            x++;
            printf("Enter the new Blood type :-\n");
            scanf("%c",&temp);
            scanf("%[^\n]",New);

            strcpy(data.bloodType,New);
            break;
        }


        case 8:
        {
            printf("Exit...... :-\n");
            break;
        }
        default:
        {
            printf(".....Wrong number.....\n");
        }

        }
    }

    if(x!=0)
    {
        //get new update
        struct Node*temp;
        //save old value
        struct Node*old;
        old=newNode(index->data);
        temp=newNode( data);


        Avl= deletion(Avl, index->data.name);

        Avl=insert(Avl,temp->data);
        if(up!=0)
        {
            Avl=insert(Avl,old->data);
            up=0;
        }

    }

}
//find a patient
struct Node* findPatient(struct Node *root,char name[])
{
    if(root==NULL)
    {
        printf("\nthis Patient name not Exist\n");

    }
    else if(strcmp(root->data.name,name)<0)
    {
        return findPatient(root->right,name);
    }
    else if(strcmp(root->data.name,name)>0)
    {
        return findPatient(root->left,name);
    }
    else if(strcmp(root->data.name,name)==0)
    {
        return root;
    }
    return NULL;


}
//find all patient that have this ilness
struct Node  *findIlness(struct Node *root,char illness[] )
{

    if(root != NULL)
    {
        findIlness(root->left,illness);
        if(strcmp(root->data.Illness,illness)==0)
        {
            printf("name: %s  gender: %s  dateOfAdmission: %s  dateOfBirth: %s  Illness: %s  address: %s  bloodType: %s\n", root->data.name,root->data.gender,root->data.dateOfAdmission,root->data.dateOfBirth,root->data.Illness,root->data.address,root->data.bloodType);
            check++;
        }
        findIlness(root->right,illness);
    }



    return NULL;

}
//insert the data from struct to tree
void insertIntoDataStruct(str s[])
{

    str data;
    int i=0;
    while(s[i].name[0]!='\0')
    {
        strcpy(data.name,s[i].name);
        strcpy(data.address,s[i].address);
        strcpy(data.bloodType,s[i].bloodType);
        strcpy(data.dateOfBirth,s[i].dateOfBirth);
        strcpy(data.dateOfAdmission,s[i].dateOfAdmission);
        strcpy(data.gender,s[i].gender);
        strcpy(data.Illness,s[i].Illness);
        //insertion
        Avl= insert(Avl,data);

        i++;

    }

}
//print the tree in pre order type
void preOrder(struct Node *root)
{


    if(root != NULL)
    {

        printf("%s  %s  %s  %s  %s  %s  %s\n", root->data.name,root->data.gender,root->data.dateOfAdmission,root->data.dateOfBirth,root->data.Illness,root->data.address,root->data.bloodType);
        preOrder(root->left);
        preOrder(root->right);

    }

}
//print the tree in in order type
void inOrder(struct Node *root)
{

    if(root != NULL)
    {
        inOrder(root->left);
        printf("name: %s ,  gender: %s ,  dateOfAdmission: %s ,  dateOfBirth: %s ,  Illness: %s ,  address: %s ,  bloodType: %s\n", root->data.name,root->data.gender,root->data.dateOfAdmission,root->data.dateOfBirth,root->data.Illness,root->data.address,root->data.bloodType);

        inOrder(root->right);

    }


}
//return the balance for the node
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
//left rotate
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}
//return new node
struct Node* newNode(str data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy( node->data.name,data.name);
    strcpy( node->data.address,data.address);
    strcpy( node->data.bloodType,  data.bloodType);
    strcpy( node->data.dateOfBirth, data.dateOfBirth );
    strcpy( node->data.Illness, data.Illness);
    strcpy( node->data.dateOfAdmission,  data.dateOfAdmission);
    strcpy( node->data.gender,data.gender);
    node->left= NULL;
    node->right= NULL;
    node->height = 1;
    return(node);
}
//return the height for the node
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
//right rotate
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}
//return max
int max (int x, int y)
{
    if(x>y)
        return x;
    else
        return y;
}
//check if node empty
int isEmpety(struct Node *root)
{
    return root==NULL;
}
//find min node in tree
struct Node *findMin(struct Node *node)
{
    if(node!=NULL)
    {
        if(node->left!=NULL)
        {
            return findMin(node->left);
        }
    }
    return node;

}
//insert new node in the tree
struct Node* insert(struct Node* node, str data)
{

    if (node == NULL)
    {
        return(newNode(data));
    }

    if (strcmp(data.name,  node->data.name)<0)
    {
        node->left  = insert(node->left, data);


    }
    else if (strcmp(data.name,  node->data.name)>0)
    {

        node->right = insert(node->right, data);

    }

    else // Equal keys are not allowed in BST
    {
        up++;
        printf("\nThe  patient  which has name (%s) is already in the tree.. sorry..we cant add-update  this name in the tree..:) \n\n",node->data.name);
        return node;
    }


    // 2. Update height
    node->height = 1 + max(height(node->left),
                           height(node->right));

    // 3. Get the balance factor
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && strcmp(data.name, node->left->data.name) <0)
        return rightRotate(node);

    // Right Right Case
    if (balance <-1 && strcmp(data.name, node->right->data.name)>0)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && strcmp(data.name, node->left->data.name) >0)

    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance <-1 && strcmp(data.name, node->right->data.name) <0)

    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
//read the file
void readFile(str s[],FILE *in)
{
    fseek(in,0,SEEK_SET);
    if(in==NULL)
    {
        printf("FILE NOT FOUND");
    }
    char c;
    c=getc(in);
    int i=0;
    int j=0;
    int x=0;
    while(c!=EOF)
    {
        if(i==0)
        {
            while(c=='\n'||c==' ')
            {
                c=getc(in);
                while(c==' ')
                {
                    c=getc(in);
                }
            }

        }
        if(c!='#'&&c!='\n')
        {
            while(c!='#'&&c!=EOF&&c!='\n')
            {

                if(x==0)
                {
                    s[i].name[j]=c;
                    c=getc(in);

                }
                if(x==1)
                {
                    s[i].gender[j]=c;
                    c=getc(in);

                }
                if(x==2)
                {
                    s[i].dateOfAdmission[j]=c;
                    c=getc(in);
                }
                if(x==3)
                {
                    s[i].dateOfBirth[j]=c;
                    c=getc(in);
                }
                if(x==4)
                {
                    s[i].Illness[j]=c;
                    c=getc(in);
                }

                if(x==5)
                {
                    s[i].address[j]=c;
                    c=getc(in);
                }
                if(x==6)
                {
                    s[i].bloodType[j]=c;


                    c=getc(in);

                }



                j++;
            }


        }

        if(c=='#')
        {
            x++;
            c=getc(in);
        }

        j=0;
        while(c=='\n')
        {
            c=getc(in);
            while(c==' ')
            {
                c=getc(in);
            }

            x=0;
            if(c!='\n'&&c!=EOF)
            {
                i++;

            }


        }
    }

}
//enter any key to continue
void continuee()
{
    char c;
    printf(".....  Enter Any Key to Continue  .....\n");
    scanf(" %c",&c);
}


