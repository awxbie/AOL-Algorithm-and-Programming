#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct {
	char location[50]; 
	char city[50]; 
	long long int price;
	int rooms; 
	int bathroom; 
	int carpark; 
	char type[50]; 
	char furnish[50]; 
} data;

//Function displayData digunakan untuk display data yang ada di file excel sebanyak row yang dimasukkan user
void displayData(data mydata[], int row, int size) {
	
	FILE *myfile = fopen("file.csv", "r"); 
	
	if (row <= 0) printf ("Number of rows must be a positive integer number\n"); 
	
	if (row < size) {
		printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");  
		for (int i = 0; i < row; i++) {
			printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
			mydata[i].type, mydata[i].furnish);
		}
	}
	else {
	printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish"); 
		for (int i = 0; i < size; i++) {
			printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
			mydata[i].type, mydata[i].furnish);
		}
	}
	fclose(myfile);
}

/*Function selectRow digunakan untuk mencari dan menampilkan semua data yang sesuai dengan query/key (kata kunci) yang diinput oleh user (searching algorithm). 
  Function ini digunakan untuk column yang memiliki tipe data string. 
  Apabila tidak ditemukan data sesuai dengan query, akan didisplay Not Found, yang berarti tidak ada data yang diminta di dalam file. */
void selectRow (data mydata[], char column[], char query[], int size) {
	
	FILE *myfile = fopen ("file.csv", "r"); 
	
	if (strcmp(column, "Location") == 0) {
		int counter = 0; 
		for (int i = 0; i < size; i++) {
			if (strcmp(query, mydata[i].location) == 0) counter++;  
		}
		if (counter > 0) {
			printf ("Data found. Detail of data: \n"); 
			printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");  
			for (int i = 0; i < size; i++) {
				if (strcmp(query, mydata[i].location) == 0) 
					printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
					mydata[i].type, mydata[i].furnish);
				}
			}
			else if (counter == 0) printf ("Data not found!\n"); 
		}
	
	else if (strcmp(column, "City") == 0) {
		int counter = 0; 
		for (int i = 0; i < size; i++) {
			if (strcmp(query, mydata[i].city) == 0) counter++;  
		}
		if (counter > 0) {
			printf ("Data found. Detail of data: \n"); 
			printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish"); 

			for (int i = 0; i < size; i++) {
				if (strcmp(query, mydata[i].city) == 0) 
					printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
					mydata[i].type, mydata[i].furnish);
				}
			}
			else if (counter == 0) printf ("Data not found!\n"); 
		}
		
	else if (strcmp(column, "Type") == 0) {
		int counter = 0;  
		for (int i = 0; i < size; i++) {
			if (strcmp(query, mydata[i].type) == 0) counter++;  
		}
		if (counter > 0) {
			printf ("Data found. Detail of data: \n"); 
			printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish"); 
				
			for (int i = 0; i < size; i++) {
				if (strcmp(query, mydata[i].type) == 0) 
					printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
					mydata[i].type, mydata[i].furnish);
				}
			}
			else if (counter == 0) printf ("Data not found!\n"); 
		}
	
	else if (strcmp(column, "Furnish") == 0) {
		int counter = 0;  
		for (int i = 0; i < size; i++) {
			if (strcmp(query, mydata[i].furnish) == 0) counter++;  
		}
		if (counter > 0) {
			printf ("Data found. Detail of data: \n"); 
			printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish"); 
				
			for (int i = 0; i < size; i++) {
				if (strcmp(query, mydata[i].furnish) == 0) 
					printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
					mydata[i].type, mydata[i].furnish);
				}
			}
			else if (counter == 0) printf ("Data not found!\n"); 
		}
}

/*Function selectRowInt digunakan untuk mencari dan menampilkan semua data yang sesuai dengan query/key (kata kunci) yang diinput oleh user (searching algorithm). 
  Function ini digunakan untuk column yang memiliki tipe data integer. 
  Apabila tidak ditemukan data sesuai dengan query, akan didisplay Not Found, yang berarti tidak ada data yang diminta di dalam file. */
void selectRowInt (data mydata[], char column[], int key, int size) {
	FILE *myfile = fopen("file.csv", "r"); 
	
	if (strcmp(column, "Price") == 0) {
		int counter = 0;  
		for (int i = 0; i < size; i++) {
			if (key == mydata[i].price) counter++;  
		}
		if (counter > 0) {
			printf ("Data found. Detail of data: \n"); 
			printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");  
				
			for (int i = 0; i < size; i++) {
				if (key == mydata[i].price)
					printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
					mydata[i].type, mydata[i].furnish);
			}
	
		}
			else if (counter == 0) printf ("Data not found!\n"); 
		}
		
	else if (strcmp(column, "Rooms") == 0) {
		int counter = 0;  
		for (int i = 0; i < size; i++) {
			if (key == mydata[i].rooms) counter++;  
		}
		if (counter > 0) {
			printf ("Data found. Detail of data: \n"); 
			printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");  
				
			for (int i = 0; i < size; i++) {
				if (key == mydata[i].rooms)
					printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
					mydata[i].type, mydata[i].furnish);
					}
				}
				else if (counter == 0) printf ("Data not found!\n"); 
		}
	
	else if (strcmp(column, "Bathrooms") == 0) {
		int counter = 0;  
		for (int i = 0; i < size; i++) {
			if (key == mydata[i].bathroom) counter++;  
		}
		if (counter > 0) {
			printf ("Data found. Detail of data: \n"); 
			printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish"); 
				
			for (int i = 0; i < size; i++) {
				if (key == mydata[i].bathroom)
					printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
					mydata[i].type, mydata[i].furnish);
				}
			}
			else if (counter == 0) printf ("Data not found!\n"); 
		}
		
	else if (strcmp(column, "Carparks") == 0) {
		int counter = 0;  
		for (int i = 0; i < size; i++) {
			if (key == mydata[i].carpark) counter++;  
		}
		if (counter > 0) {
			printf ("Data found. Detail of data: \n"); 
			printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathrooms", "CarParks", "Type", "Furnish");  
				
			for (int i = 0; i < size; i++) {
				if (key == mydata[i].carpark)
					printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms, mydata[i].bathroom, mydata[i].carpark,
					mydata[i].type, mydata[i].furnish);
				}
			}
			else if (counter == 0) printf ("Data not found!\n"); 
		}
		fclose(myfile); 
}

//Function swap digunakan untuk menukar dua struct yang bersangkutan (digunakan untuk sorting)
void swap (data *a, data *b) {
	data temp = *a; 
	*a = *b; 
	*b = temp; 
}

/*Function sortBy digunakan untuk menyorting data pada column tertentu secara ascending atau descending (column dan methods tergantung input dari user). 
  Setelah data sudah disorting (sudah berurut), akan ditampilkan 10 data teratas. */
void sortBy (data mydata[], char column[], char methods[], int size) {
	
	FILE *myfile = fopen ("file.csv", "r"); 
	
	if (strcmp(column, "Location") == 0) {
		if (strcmp(methods, "asc") == 0 || strcmp(methods, "ascending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (strcmp(mydata[j].location, mydata[j+1].location) > 0) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
		else if (strcmp(methods, "dsc") == 0 || strcmp(methods, "descending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (strcmp(mydata[j].location, mydata[j+1].location) < 0) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
	}
	
	else if (strcmp(column, "City") == 0) {
		if (strcmp(methods, "asc") == 0 || strcmp(methods, "ascending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (strcmp(mydata[j].city, mydata[j+1].city) > 0) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
		else if (strcmp(methods, "dsc") == 0 || strcmp(methods, "descending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (strcmp(mydata[j].city, mydata[j+1].city) < 0) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
	}
	
	else if (strcmp(column, "Price") == 0) {
		if (strcmp(methods, "asc") == 0 || strcmp(methods, "ascending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (mydata[j].price > mydata[j+1].price) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
		else if (strcmp(methods, "dsc") == 0 || strcmp(methods, "descending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (mydata[j].price < mydata[j+1].price) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
	}
	
	else if (strcmp(column, "Rooms") == 0) {
		if (strcmp(methods, "asc") == 0 || strcmp(methods, "ascending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (mydata[j].rooms > mydata[j+1].rooms) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
		else if (strcmp(methods, "dsc") == 0 || strcmp(methods, "descending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (mydata[j].rooms < mydata[j+1].rooms) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
	}
	
	else if (strcmp(column, "Bathrooms") == 0) {
		if (strcmp(methods, "asc") == 0 || strcmp(methods, "ascending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (mydata[j].bathroom > mydata[j+1].bathroom) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
		else if (strcmp(methods, "dsc") == 0 || strcmp(methods, "descending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (mydata[j].bathroom < mydata[j+1].bathroom) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
	}

	else if (strcmp(column, "CarParks") == 0) {
		if (strcmp(methods, "asc") == 0 || strcmp(methods, "ascending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (mydata[j].carpark > mydata[j+1].carpark) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
		else if (strcmp(methods, "dsc") == 0 || strcmp(methods, "descending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (mydata[j].carpark < mydata[j+1].carpark) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
	}
	
	else if (strcmp(column, "Type") == 0) {
		if (strcmp(methods, "asc") == 0 || strcmp(methods, "ascending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (strcmp(mydata[j].type, mydata[j+1].type) > 0) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
		else if (strcmp(methods, "dsc") == 0 || strcmp(methods, "descending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (strcmp(mydata[j].type, mydata[j+1].type) < 0) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
	}
	
	else if (strcmp(column, "Furnish") == 0) {
		if (strcmp(methods, "asc") == 0 || strcmp(methods, "ascending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (strcmp(mydata[j].furnish, mydata[j+1].furnish) > 0) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
		else if (strcmp(methods, "dsc") == 0 || strcmp(methods, "descending") == 0) {
			for (int i = 0; i < size-1; i++) {
				for (int j = 0; j < size-1-i; j++) {
					if (strcmp(mydata[j].furnish, mydata[j+1].furnish) < 0) 
					swap (&mydata[j], &mydata[j+1]); 
				}
			}
		}
	}
	fclose(myfile); 
}

//Function printData digunakan untuk mendisplay data yang ada di struct
void printData(data mydata[]) {
	printf ("Data found. Detail of data: \n"); 
	printf ("%-26s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Location", "City", "Price", "Rooms", "Bathroom", "CarParks", "Type", "Furnish"); 
	
		for (int a = 0; a < 10; a++) {
			printf ("%-26s %-15s %-10lld %-10d %-10d %-10d %-10s %-10s\n", mydata[a].location, mydata[a].city, mydata[a].price, mydata[a].rooms, mydata[a].bathroom, mydata[a].carpark,
			mydata[a].type, mydata[a].furnish);
		}
}

/*Function exportFile digunakan untuk membuat (menulis) data ke file baru dengan format .csv (comma separated value). Nama file baru akan sesuai dengan nama yang diinput oleh user.
  Sebelum menulis file baru, function ini akan mengecek terlebih dahulu apakah file name yang diinput user sudah memiliki format .csv atau belum. 
  Apabila belum, format .csv akan ditambahkan ke dalam file name. */
void exportFile(data mydata[], char fileName[], int size) {
	
	FILE *myfile; 
	
	char string[5] = ".csv"; 
	
	char *result; 
	result = strstr(fileName, string); 
	
	if (result) {
		myfile = fopen (fileName, "w"); 
		fprintf (myfile, "Location,City,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n"); 
		for (int i = 0; i < size; i++) {
			fprintf (myfile, "%s,%s,%lld,%d,%d,%d,%s,%s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms,
			mydata[i].bathroom, mydata[i].carpark, mydata[i].type, mydata[i].furnish); 
		}
	
		if (myfile != NULL) {
			printf ("Data successfully written to file %s!\n", fileName); 
		}
		else printf ("Data failed to export!\n"); 
	}
	
	else {
		int len = strlen(fileName); 
		int index = 0; 
	
		for (int i = len; i < len + 4 && index < 4; i++) {
			fileName[i] = string[index]; 
			index++; 
		}
		fileName[len + index] = '\0'; 
		
		myfile = fopen (fileName, "w"); 
		
		fprintf (myfile, "Location,City,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n"); 
		for (int i = 0; i < size; i++) {
			fprintf (myfile, "%s,%s,%lld,%d,%d,%d,%s,%s\n", mydata[i].location, mydata[i].city, mydata[i].price, mydata[i].rooms,
			mydata[i].bathroom, mydata[i].carpark, mydata[i].type, mydata[i].furnish); 
		}
	
		if (myfile != NULL) {
			printf ("Data successfully written to file %s!\n", fileName); 
		}
		else printf ("Data failed to export!\n"); 
	}
	
	fclose(myfile); 
}

int main() {
	data mydata[4000]; 
	
	int choice;  
	
	FILE *myfile = fopen("file.csv", "r"); 
	
	int i = 0;  
	
	fscanf (myfile, "%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n");
	
	while (!feof(myfile)) {
		fscanf (myfile, "%[^,],%[^,],%lld,%d,%d,%d,%[^,],%[^\n]\n", mydata[i].location, mydata[i].city, &mydata[i].price, 
		&mydata[i].rooms, &mydata[i].bathroom, &mydata[i].carpark, mydata[i].type, mydata[i].furnish); 
		i++; 
	}
	
	int size = i; 
	
	do{
		printf ("\nWhat do you want to do?\n"); 
		printf ("1. Display data\n"); 
		printf ("2. Search data\n"); 
		printf ("3. Sort data\n"); 
		printf ("4. Export data\n"); 
		printf ("5. Exit\n"); 
		printf ("Your choice: "); 
		scanf ("%d", &choice); 
	
	switch (choice) 
	{
		case 1: {
			int row; 
			printf ("Number of rows: "); 
			scanf ("%d", &row); 
			displayData(mydata, row, size); 
			getchar(); 
			break;
		}
		case 2: {
			char column[100]; 
			char query[100]; 
			int key; 
			do {
				printf ("Choose column: "); 
				scanf ("%s", column); getchar(); 
				
				int panjang = strlen(column); 
				
				column[0] = toupper(column[0]); 
				for (int i = 1; i < panjang; i++) {
					column[i] = tolower(column[i]); 
				}
				
			} while (strcmp(column, "Location") != 0 && strcmp(column, "City") != 0 && strcmp (column, "Price") != 0 && strcmp(column, "Rooms") != 0 && strcmp(column, "Bathrooms") != 0
					&& strcmp(column, "Carparks") != 0 && strcmp(column, "Type") != 0 && strcmp(column, "Furnish") != 0); 
					
			if (strcmp(column, "Price") == 0 || strcmp(column, "Rooms") == 0 || strcmp(column, "Bathrooms") == 0 || strcmp(column, "Carparks") == 0) {
				printf ("What data do you want to find? "); 
				scanf ("%d", &key); getchar(); 
				selectRowInt(mydata, column, key, size); 
			}
			else {
				printf ("What data do you want to find? "); 
				scanf ("%s", query); getchar(); 
				selectRow(mydata, column, query, size); 
			}
		}
			break;
		case 3: {
			char column[100]; 
			char methods[10]; 
			do {
				printf ("Choose column: "); 
				scanf ("%s", column); getchar(); 
				
				int panjang = strlen(column); 
				
				column[0] = toupper(column[0]); 
				for (int i = 1; i < panjang; i++) {
					column[i] = tolower(column[i]); 
				}	
				
			} while (strcmp(column, "Location") != 0 && strcmp(column, "City") != 0 && strcmp (column, "Price") != 0 && strcmp(column, "Rooms") != 0 && strcmp(column, "Bathrooms") != 0
					&& strcmp(column, "Carparks") != 0 && strcmp(column, "Type") != 0 && strcmp(column, "Furnish") != 0); 
				
			do {
				printf ("Sort ascending or descending? "); 
				scanf ("%s", methods); getchar(); 
			
				int lengths = strlen(methods); 
				for (int i = 0; i < lengths; i++) {
					methods[i] = tolower(methods[i]); 
				} 
			} while (strcmp(methods, "ascending") != 0 && strcmp(methods, "asc") != 0 && strcmp(methods, "descending") != 0 && strcmp(methods, "dsc") != 0); 
			
			sortBy(mydata, column, methods, size);  
			printData(mydata); 
			break;
		}
		case 4: {
			char fileName[100]; 
			printf ("File name: "); 
			scanf ("%s", fileName); getchar(); 
			exportFile(mydata, fileName, size); 
			break;
		}
	}
		printf("Press enter to continue...\n"); 
		getchar(); 
		system("cls"); 
		
	} while (choice >= 1 && choice <= 4 && choice != 5); 
	
	fclose(myfile); 
	
	return 0; 
}
