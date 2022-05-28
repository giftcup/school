CREATE DATABASE Orders;

USE Orders;

CREATE TABLE Customers (
    CustomerID VARCHAR(5) NULL,
    CompanyName VARCHAR(40) NOT NULL UNIQUE,
    ContactName VARCHAR(30) NULL,
    ContactTitle VARCHAR(30) NULL,
    Address VARCHAR(60) NULL,
    City VARCHAR(15) NULL,
    Region VARCHAR(15) NULL,
    PostalCode VARCHAR(10) NULL,
    Country VARCHAR(15) NULL DEFAULT "Canada",
    Phone VARCHAR(24) NULL,
    Fax VARCHAR(24) NULL,
    PRIMARY KEY (CustomerID)
);

CREATE TABLE Shippers (
    ShipperID INT NOT NULL,
    CompanyName VARCHAR(40) NOT NULL UNIQUE,
    PRIMARY KEY(ShipperID)
);

CREATE TABLE Supplier (
    SupplierID INT NOT NULL,
    Name VARCHAR(50) NULL,
    Address VARCHAR(50) NULL,
    City VARCHAR(50) NULL,
    Province VARCHAR(50) NULL,
    PRIMARY KEY (SupplierID)
);

CREATE TABLE Orders (
    OrderID INT NULL,
    CustomerID VARCHAR(5) NOT NULL,
    EmployeeID INT NULL,
    ShipName VARCHAR(40) NULL,
    ShipAddress VARCHAR(60) NULL,
    ShipCity VARCHAR(15) NULL,
    ShipRegion VARCHAR(15) NULL,
    ShipPostalCode VARCHAR(10) NULL,
    ShipCountry VARCHAR(15) NULL,
    ShipVia INT NULL,
    OrderDate DATETIME NULL,
    RequiredDate DATETIME NULL,
    ShippedDate DATETIME NULL CHECK (ShippedDate > OrderDate),
    Freight REAL NULL,
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (ShipVia) REFERENCES Shippers(ShipperID) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY (OrderID)
);

CREATE TABLE Products (
    ProductID INT NOT NULL,
    SupplierID INT NULL,
    CategoryID INT NULL,
    ProductName VARCHAR(40) NOT NULL,
    EnglishName VARCHAR(40) NULL,
    QuantityPerUnit VARCHAR(20) NULL,
    UnitPrice REAL NULL,
    UnitsInStock SMALLINT NULL,
    UnitsOnOrder SMALLINT NULL,
    ReorderLevel SMALLINT NULL,
    Discontinued BIT NOT NULL,
    FOREIGN KEY (SupplierID) REFERENCES Supplier(SupplierID) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY (ProductID)
);

CREATE TABLE OrderDetails (
    OrderID INT NULL,
    ProductID INT NOT NULL,
    UnitPrice REAL NOT NULL,
    Quantity SMALLINT NOT NULL CHECK (Quantity > 0),
    Discount REAL NOT NULL,
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (ProductID) REFERENCES Products(ProductID) ON DELETE CASCADE ON UPDATE CASCADE,
    PRIMARY KEY (OrderID, ProductID)
);

-- inserts.sql --

--- QUESTIONS 1 ---
SELECT Customers.CustomerID, Orders.OrderID, Orders.OrderDate FROM (Customers INNER JOIN Orders ON Orders.CustomerID = Customers.CustomerID) WHERE DATE(Orders.OrderDate) BETWEEN '2014-01-01' AND '2014-12-31';


--- QUESTION 2 ---
ALTER TABLE Customers ADD Active BOOLEAN DEFAULT true;

--- QUESTION 3 ---
SELECT Customers.CompanyName, Orders.OrderDate, Order.Freight + (OrderDetails.UnitPrice * OrderDetails.Quantity) AS Total_Amount
    FROM (Customers INNER JOIN Orders ON Customers.CustomerID = Orders.CustomerID)
    INNER JOIN OrderDetails ON Orders.OrderID = OrderDetails.OrderID
    WHERE Orders.OrderDate < '2012-09-01 00:00:00';


--- QUESTION 4 ---
SELECT Orders.OrderID, Shippers.CompanyName, Customers.CustomerID FROM (Orders INNER JOIN Shippers ON Orders.ShipVia = Shippers.ShipperID) INNER JOIN Customers ON Customers.CustomerID = Orders.CustomerID WHERE Shippers.CompanyName = 'Federal Shipping';

--- QUESTION 5 ---
SELECT Customers.CustomerID, Customers.ContactName, Orders.OrderDate FROM (Orders INNER JOIN Customers ON Orders.CustomerID = Customers.CustomerID) WHERE Orders.OrderDate NOT BETWEEN '2011-01-01' AND '2011-12-31';

--- QUESTION 6 ---
SELECT Products.ProductID, Products.ProductName FROM Products WHERE UnitsOnOrder = 0;

--- QUESTION 7 ---
SELECT Customers.CustomerID, Customers.ContactName, Orders.OrderID FROM (Customers INNER JOIN Orders ON Orders.CustomerID = Customers.CustomerID) WHERE Customers.CustomerID IN (SELECT Customers.CustomerID FROM Customers
WHERE Customers.City = 'London');

--- QUESTION 8 ---
SELECT Products.ProductName, Supplier.Name FROM (Products INNER JOIN Supplier ON Products.SupplierID = Supplier.SupplierID) WHERE Supplier.Name = 'Supplier A' OR Supplier.Name = 'Supplier B';

--- QUESTION 9 ---
SELECT Products.ProductName, Products.QuantityPerUnit FROM Products WHERE Products.QuantityPerUnit LIKE '%boxes%';

--- PART 3 ---
--- QUESTION 1 ---
CREATE TABLE Employee (
    EmployeeID INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    LastName TEXT NULL,
    FirstName TEXT NULL,
    Address TEXT NULL,
    City TEXT NULL,
    Province TEXT NULL,
    Postalcode TEXT NULL,
    Phone TEXT NULL,
    Salary REAL NULL
);

INSERT INTO Employee (LastName, FirstName, Address, City, Province, Postalcode, Phone, Salary) VALUES ('Salome', 'Tambe', 'Molyko', 'Buea', 'South West', 'P.O Box 67', '678201083', 10000000);

INSERT INTO Employee (LastName, FirstName, Address, City, Province, Postalcode, Phone, Salary) VALUES ('Tabi', 'Edwin', 'Sandpit', 'Yaounde', 'South West', 'P.O Box 88', '678901083', 1000000);

INSERT INTO Employee (LastName, FirstName, Address, City, Province, Postalcode, Phone, Salary) VALUES ('Acha', 'Sonia', 'Bakweri town', 'Limbe', 'North', 'P.O Box 77', '689721083', 20000000);

INSERT INTO Employee (LastName, FirstName, Address, City, Province, Postalcode, Phone, Salary) VALUES ('Francis', 'Atem', 'Bomaka', 'Douala', 'West', 'P.O Box 697', '678201084', 1800000);

INSERT INTO Employee (LastName, FirstName, Address, City, Province, Postalcode, Phone, Salary) VALUES ('Bessong', 'Tabi', 'Street two', 'Foumbot', 'Littoral', 'P.O Box 7', '678201084', 6800000);

ALTER TABLE Orders ADD FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID);

ALTER TABLE Orders ADD TotalSales INT NULL;

UPDATE Orders
SET TotalSales = (SELECT COUNT(OrderID) FROM OrderDetails WHERE Orders.OrderID = OrderDetails.OrderID);