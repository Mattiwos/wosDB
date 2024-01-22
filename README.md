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
./bin/main -s
```
starts server @8080 with local addr  

### Test wosDB server with client
```
make  
./bin/main -c [port:: (use 8080)]
```

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


## Test Tools:  
- valgrind  

