/*
 * =====================================================================================
 *
 *       Filename:  Games.hpp
 *
 *    Description: Games section in market.
 *        Command: g++ main.cpp -std=c++2a -lpqxx -lpq -lpthread -pthread 
 *
 *        Version:  1.0
 *        Created:  2020-04-10 01:35:52 AM
 *       Compiler:  g++
 *
 *         Author:  Safa Bayar (rection), safa@safabayar.tech
 *   Organization:
 *
 * =====================================================================================
 */

class Games{
public:
	void RemoveWithID(int ID){
		string sql = "DELETE FROM books WHERE id = '" + InttoString(ID) + "';";
		PostgresConnection PostgresConn;
       	        if ( PostgresConn.setAdd(sql) == 0 ){
       	          	std::cout << "The record added successfully!";
       	          }else{
       	          	std::cout << "Something Gone Wrong!";
       	        }

	}
	void RemoveWithName(string Name){
		string sql = "DELETE FROM books WHERE productname = '" + Name + "';";
		PostgresConnection PostgresConn;
       	        if ( PostgresConn.setAdd(sql) == 0 ){
       	          	std::cout << "The record added successfully!";
       	          }else{
       	          	std::cout << "Something Gone Wrong!";
       	        }
	
	}
    void add(){
    	string sql, GameName, BrandName;
        int ProductYear;
        float Price;
        Games Gameobj;
        std::cout << "Game Name: " << std::endl;
        std::cin >> GameName;
        std::cout << "Brand Name: " << std::endl;
        std::cin >> BrandName;
        std::cout << "Price: (Sample 4.54)" << std::endl;
        std::cin >> Price;
        std::cout << "Product Year: " << std::endl;
        std::cin >> ProductYear;
        sql = "INSERT INTO games (PRODUCTNAME,BRANDNAME,PRICE,PRODUCTYEAR) VALUES ('" + GameName + "','" + BrandName  + "','$" + InttoString(Price) + "','" + InttoString(ProductYear) +"');";
        PostgresConnection PostgresConn;
        if ( PostgresConn.setAdd(sql) == 0 ){
          	std::cout << "The record added successfully!";
          }else{
          	std::cout << "Something Gone Wrong!";
        }
    }
    string InttoString(int number){
        ostringstream temp;
        temp << number;
        return temp.str();
    }
};  
	
	
