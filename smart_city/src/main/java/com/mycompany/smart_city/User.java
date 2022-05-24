/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.smart_city;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author pro-3is
 */
public class User {

    public static void search_hotel(ArrayList<Hotel> hotels) {

        String town;
        int choice;
        int evaluation;
        Scanner read = new Scanner(System.in);

        do {
            System.out.println("\n\n1. Search Hotel by town\n2. Search Hotel by Evaluation\n3. Quit\n\n");
            choice = read.nextInt();

            switch (choice) {
                case 1 -> {
                    read.nextLine();
                    System.out.println("Enter town: ");
                    town = read.nextLine();

                    for (int i = 0; i < hotels.size(); i++) {
                        if (hotels.get(i).town.equals(town)) {
                            System.out.println(i + 1 + "." + hotels.get(i) + "\n");
                        }
                    }

                    User.inc_recommendation(hotels);

                }
                case 2 -> {
                    System.out.println("Enter evaluation: ");
                    evaluation = read.nextInt();

                    for (int i = 0; i < hotels.size(); i++) {
                        if (hotels.get(i).evaluation == evaluation) {
                            System.out.println(hotels.get(i));
                        }
                    }
                }
                case 3 -> {
                    System.out.println("\n\n  See you soon  \n\n");
                }
            }
        } while (choice != 3);
    }

    /**
     *
     * @param hotels
     */
    public static void inc_recommendation(ArrayList<Hotel> hotels) {
        int choice;
        int hotel_num;
        Scanner read = new Scanner(System.in);

        System.out.println("Recommend hotel(y/n): ");
        choice = read.next().charAt(0);
        read.nextLine();

        if (choice == 'y') {
            System.out.println("Enter hotel number from above: ");
            hotel_num = read.nextInt();
            hotels.get(hotel_num - 1).increment_recommendation();
        }
    }

    public static void userSubroutine(ArrayList<Hotel> hotels) {
        int choice;
        Scanner read = new Scanner(System.in);

        do {
            System.out.println("\n++++++++++++++++++++++++++++++++++++++++++++\n");
            System.out.println("+++++++++++++++++++ USER +++++++++++++++++++\n");
            System.out.println("++++++++++++++++++++++++++++++++++++++++++++\n");

            System.out.println("\nEnter what the number corresponding to the task");
            System.out.println("1. Search Hotel\n2. Quit");

            choice = read.nextInt();

            switch (choice) {
                case 1 -> {
                    User.search_hotel(hotels);
                }
                case 2 -> {
                    System.out.println("See you soon\n\n");
                }
            }

        } while (choice != 2);
    }
}
