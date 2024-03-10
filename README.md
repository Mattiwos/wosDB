# wosDB
A database created using C which is able to store both key and value data and document-oriented data.  

## Instructions:  

### Building the project

Use the `make all` command to build the binary file for wosDB.

### Running wosDB

Use the `./wosDB -flag` command to run the database. The behavior of the database is determined by the flag and input.

#### Flags

- `s`: Starts the server and listens on port 8080 by default.
- `-c <input>`: Creates a database named after the input.
- `-d <input>`: Deletes a database named after the input.
- `-l`: Lists current databases in the manifest.

### Starting the wosDB server

Use the following commands to start the server after building:

```bash
./bin/wosDB -s
```
starts server @8080 with local addr  

## Building with CMake

CMake is used to control the software compilation process using simple platform and compiler independent configuration files. CMake generates native makefiles and workspaces that can be used in the compiler environment of your choice.

Follow these steps to build the project using CMake:

1. Navigate to the project directory.

2. Create a new directory for the build outputs:

    ```bash
    mkdir build bin
    cd build
    ```

3. Run CMake to generate the Makefile:

    ```bash
    cmake ..
    ```

4. Build the project:

    ```bash
    make
    ```
5. Run the project:

    ```bash
    cd ../
    ./bin/wosDB -s
    ```
This will create the `wosDB` executable in the `bin` directory.

## Plan:    
- [x] DB has its own server running to recieve request from
      the user 
- [ in-progress ] Work on scalable messageProtocol used for DB  
- [ ] Each DB has its own manifest  
- [ ] DB has two types Key/Value and Document  
- [ ] Be able to find, add, delete data
- [ ] Test efficancy using it as a database for wosCV  
- [ ] Add the ability to regex documment to find matching tables and
      return it to the user  
- [ ] Create ability to encode and decode data  
- [ ] Create a hybrid type database  (find,add,delete)  
- [ ] Add diagnostic ability for database to check viability  
- [ ] Add the ability to compress data  
- [ ] Create a long-term data storage type with maxium reliability  


## Test Tools:  
- valgrind  

## Contributors ✨  
<table>
  <tbody>
    <tr>  
            <td align="center" valign="top" width="14.28%">
              <a href="https://github.com/Mattiwos">
                <img src="https://avatars.githubusercontent.com/u/44147357?v=4" width="100px;" alt="Jeroen Engels"/>
                <br />
                <sub><b>Mattiwos</b></sub>
              </a><br />
              <a href="https://github.com/mattiwos/wosDB/commits?author=mattiwos" title="Documentation">📖</a> <a href="https://github.com/mattiwos/wosDB/pulls?q=mattiwos" title="Reviewed Pull Requests">👀</a> 
              <a href="#tool-mattiwos" title="Tools">🔧</a>
          </td>
  </tr> 

  </tbody>
</table>


