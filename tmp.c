



char **string_arr;

string_arr = (char**)malloc(10 * sizeof(char*));
for (int i = 0; i < 10; i ++){
string_arr[i] = (char*)malloc(5*sizeof(char));
}

