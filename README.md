# wosDB
A database created using C which is able to store
both key and value data and document-oriented data.  

## Instruction:  

### make all  
- Makes the binary file for wosDB

### ./wosDB -flag  
- Runs databases and instruciton
is determined by flag and input  
#### -flag:  
- s: starts server to listen to port 8080 (default)  
- -c **input**: creates a databases named after input  
- -d **input**: deletes a databases named after input  
- -l: lists current databases in manifest  

### Start Up wosDB server
```
make  
./wosDB -s
```
starts server @8080 with local addr  

## Plan:    
- [ ] Each DB has its own manifest  
- [ ] DB has two types Key/Value and Document  
- [ ] Be able to find, add, delete data
- [ ] DB has its own server running to recieve request from
      the user  
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

