/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.smart_city;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author pro-3is
 */
public class Main {
    
    static ArrayList<Hotel> hotels = new ArrayList<Hotel>(1);
    
    public static void main(String[] args) throws IOException {
        
        int choice;
        Scanner read = new Scanner(System.in);
        
        do {
            System.out.println("++++++++++++++++++++++++++++++++++++++++++++\n");
            System.out.println("+++++++++++++++++ WELCOME ++++++++++++++++++\n");
            System.out.println("++++++++++++++++++++++++++++++++++++++++++++\n");
            
            System.out.println("1. Admin \n2. User\n3. Exit\n");
            System.out.println("Select User type (number): ");
            
            choice = read.nextInt();
            
            switch (choice) {
                case 1 -> Admin.adminSubroutine(hotels);
                case 2 -> 
                    User.userSubroutine(hotels);
                case 3 -> {
                    System.out.println("\n\n See you another time!! \n\n");
                }
            }
            
        } while(choice != 3);
    }
    
}
