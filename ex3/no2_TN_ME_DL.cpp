#include <iostream>

//Function declarations
int myFunction(int&, int&);
int myFunctionPt(int*, int*);
double scalarProduct(double*, double*, int);
void vectorProduct(double*, double*, double*);

int main ()
{
    int intArray[]={1,2,3};
    double doubleArray[]={1.0,2.0,3.0};
    long double longDoubleArray[]={1.01,2.01,3.01};

    /* 
     * Define pointers that point to the array's references.
     * Don't need &, because arrays are already references.
     */

    int* intPt=intArray;
    double* doublePt=doubleArray;
    long double* longDoublePt=longDoubleArray;

    std::cout << "-----------------------" << std::endl;
    std::cout << "Part a):" << std::endl;
    std::cout << "-----------------------" << std::endl;

    std::cout << std::endl;
    std::cout << "Addresses of different arrays:" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "intArray address: " << intPt << std::endl;
    std::cout << "doubleArray address: " << doublePt << std::endl;
    std::cout << "longDoubleArray address: " << longDoublePt << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    

    //Increment pointers
    intPt++;
    doublePt++;
    longDoublePt++;

    std::cout << "Addresses of different arrays after incrementation:" << std::endl;
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
    std::cout << "intArray address and element after incrementing pointer: " << intPt << " " << *intPt << std::endl;
    std::cout << "doubleArray address and element after incrementing pointer: " << doublePt << " " << *doublePt << std::endl;
    std::cout << "longDoubleArray address and element after incrementing pointer: " << longDoublePt << " " << *longDoublePt << std::endl;
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;

    /* 
     * The int address changes only by little (e.g. 4 bytes). The double address changes by 8 bytes. 
     * The long double changes the most (16 bytes). This corresponds to the memory size of the data types, respectively.
     */

    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Part b):" << std::endl;
    std::cout << "-----------------------" << std::endl;

    //Decrement pointers
    intPt--;
    doublePt--;
    longDoublePt--;

    std::cout << std::endl;
    std::cout << "Addresses of different arrays:" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "intArray address: " << reinterpret_cast<intptr_t>(intPt) << "  ";
    intPt++;
    std::cout << reinterpret_cast<intptr_t>(intPt) << std::endl;
    std::cout << "doubleArray address: " << reinterpret_cast<intptr_t>(doublePt) << "  ";
    doublePt++;
    std::cout << reinterpret_cast<intptr_t>(doublePt) << std::endl;
    std::cout << "longDoubleArray address: " << reinterpret_cast<intptr_t>(longDoublePt) << "  ";
    longDoublePt++;
    std::cout << reinterpret_cast<intptr_t>(longDoublePt) << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    /*
     * Having the decimal representation of the pointer, one can clearly see the memory size of each data type.
     * The difference of both numbers of the addresses correspond to the memory size.
     */ 

    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Part c):" << std::endl;
    std::cout << "-----------------------" << std::endl;

    int x=2,y=4;

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << x << std::endl;
    std::cout << "Product of x and y with references: " << myFunction(x, y) << std::endl;
    std::cout << "Product of x and y with pointers: " << myFunctionPt(&x, &y) << std::endl;
    std::cout << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    double arr1[]={1.0,2.0,3.0};
    double arr2[]={2.0,3.0,4.0};
    int size=sizeof(arr1)/sizeof(arr1[0]); //calculation the number of entries of the array

    std::cout << "The following two arrays will be used for the calculations in d) and e)." << std::endl;
    for(int i=0; i<size; i++){
        std::cout << "arr1[" << i << "]=" << arr1[i] << "   " << "arr2[" << i << "]=" << arr2[i] << std::endl; 
    }

    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Part d):" << std::endl;
    std::cout << "-----------------------" << std::endl;


    std::cout << "Scalar product of arr1 and arr2: " << scalarProduct(arr1, arr2, size) << std::endl;

    std::cout << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "Part e):" << std::endl;
    std::cout << "-----------------------" << std::endl;

    std::cout << "Vector product of arr1 and arr2: " << std::endl;

    double result[3];
    vectorProduct(arr1, arr2, result);
    for(int i=0; i<3; i++)
        std::cout << "result[" << i << "]=" << result[i] << std::endl;

    return 0;
}

//Function definitions

int myFunction(int &x, int &y)
{
    return x*y; 
}

int myFunctionPt(int* x, int* y)
{
    return (*x)*(*y); 
}

double scalarProduct(double*  arr1, double* arr2, int len)
{
    double scalarProduct=0;
    for(int i=0; i<len; i++){
        scalarProduct+=(*arr1)*(*arr2);
        arr1++; //need to increment pointer because pointer only points to one entry, starting with the first
        arr2++;
    }
    return scalarProduct;
}

void vectorProduct(double* arr1, double* arr2, double* result)
{
    double tempArr1[3]; //Defined two arrays because otherwise you have to incerement and decrement the pointers multiple times to get the correct entries
    double tempArr2[3]; //It is allowed to hard code the size here, because the vector product only applies to 3dim vectors
    for(int i=0; i<3; i++){
        tempArr1[i]=*arr1; //writing the arrays given as arguments into the temporary arrays
        tempArr2[i]=*arr2;
        arr1++;
        arr2++;
    }
    *result=tempArr1[1]*tempArr2[2] - tempArr1[2]*tempArr2[1]; //Using the definition of the vector product for every entry
    result++;
    *result=tempArr1[2]*tempArr2[0] - tempArr1[0]*tempArr2[2];
    result++;
    *result=tempArr1[0]*tempArr2[1] - tempArr1[1]*tempArr2[0];
}