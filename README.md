<h1 align="center">D'BengkelTelU </h1>

<h1 align="center"><a href="https://skillicons.dev"><img src="https://skillicons.dev/icons?i=vscode,github,c" alt="Tubes Daskom"></a></h1>


Project : C.1.0

Description : D'BengkelTelU is a service order application from workshops located around telkom university. The application is intended to help teachers, students, and college activists who are having problems with their vehicles. It enables them to find nearby workshops around the campus and easily contact the mechanic from the one they choose to help. This simple application was developed using C programming language.

Member : 
- [Aliza Nurfitrian Meizahra ](https://github.com/Alizaaaja4) [ALL]
  > Practicum Assistant at Basic Computing Laboratory <br>
- Hisyam Aqiel Sadzili [OIL]
  > Practicum Assistant at Basic Computing Laboratory <br>
- Muhammad Nabil Arifiandi Tambunan [NST]
  > Practicum Assistant at Basic Computing Laboratory <br>


### BINARY FILE
Binary files can store various types of data, including images, audio, video, compiled programs, or any data that doesn't consist of plain text. These files are typically used to store information that is structured in a way that is more efficient for a computer to process than a human-readable text file.

#### Writing and Reading Data in Binary Files
    size_t fread(void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);
    
    size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb, FILE * restrict stream);

#### Add Data to the Binary File
    f_structure = fopen("Price List.dat", "ab");
    
    fwrite(&list, sizeof(list), 1, f_structure);

#### Access Binary Files Randomly
    int fseek(FILE *stream, long int offset, int whence);

#### Erasing Data in Binary Files
    f_structure = fopen("Price List.dat", "rb");
    f_structure2 =fopen("Price List2.dat", "wb");

    while (fread(&list, sizeof(list), 1, f_structure) == 1){
      if (strcmp(list.Menu, toFind) != 0){
        fwrite(&list, sizeof(list), 1, f_structure2);
      }
      
    fclose(f_structure);
    fclose(f_structure2);
    
    remove("Price List.dat");
    rename("Price List2.dat", "Price List.dat");

#### Close file
    int fclose(FILE *stream);
    
<img width=100% src="https://capsule-render.vercel.app/api?type=waving&color=007FFF&height=120&section=footer"/>
