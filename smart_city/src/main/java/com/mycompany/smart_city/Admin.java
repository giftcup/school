/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.smart_city;

import static com.mycompany.smart_city.Main.hotels;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author pro-3is
 */
public class Admin extends User {

    static Hotel create_hotel() {
        String hotel_name;
        int hotel_price;
        int evaluation;
        String town;

        Scanner read = new Scanner(System.in);

        System.out.println("Enter hotel name: ");
        hotel_name = read.nextLine();
        System.out.println("Enter town: ");
        town = read.nextLine();
        System.out.println("Enter hotel price: ");
        hotel_price = read.nextInt();
        System.out.println("Enter evaluation: ");
        evaluation = read.nextInt();

        Hotel newHotel = new Hotel(hotel_name, hotel_price, evaluation, town);

        return newHotel;
    }

    public static void adminSubroutine(ArrayList<Hotel> hotels) {
        int choice;
        int num_hotels;
        Scanner read = new Scanner(System.in);

        do {
            System.out.println("\n\n++++++++++++++++++++++++++++++++++++++++++++\n");
            System.out.println("+++++++++++++ ADMINISTRATOR ++++++++++++++++\n");
            System.out.println("++++++++++++++++++++++++++++++++++++++++++++\n");

            System.out.println("Enter what the number corresponding to the task");
            System.out.println("1. Register a hotel\n2. Go to User\n3.Exit\n");

            choice = read.nextInt();

            switch (choice) {
                case 1 -> {
                    System.out.println("How many hotels are to be registered: ");
                    num_hotels = read.nextInt();

                    if (num_hotels != 0) {
                        for (int i = 0; i < num_hotels; i++) {
                            System.out.println("**** Hotel number " + (i + 1) + "****");

                            Hotel newHotel = Admin.create_hotel();
                            hotels.add(newHotel);
                        }
                    }

                    for (int i = 0; i < hotels.size(); i++) {
                        System.out.println(hotels.get(i));
                    }
                }
                case 2 ->
                    User.userSubroutine(hotels);
                case 3 -> {
                    System.out.println("See you soon\n\n");
                }
            }

        } while (choice != 2);
    }
}
