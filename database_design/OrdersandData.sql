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

SELECT Customers.CustomerID, Orders.OrderID, Orders.OrderDate FROM (Customers INNER JOIN Orders ON Orders.CustomerID = Customers.CustomerID) WHERE DATE(Orders.OrderDate) BETWEEN '1992-01-01' AND '1992-12-31';

ALTER TABLE Customers ADD Active BOOLEAN DEFAULT true;

SELECT Customers.CompanyName, Orders.OrderDate, Order.Freight + (OrderDetails.UnitPrice * OrderDetails.Quantity) AS Total_Amount
    FROM (Customers INNER JOIN Orders ON Customers.CustomerID = Orders.CustomerID)
    INNER JOIN OrderDetails ON Orders.OrderID = OrderDetails.OrderID
    WHERE Orders.OrderDate < '2012-09-01 00:00:00';

SELECT Orders.OrderID, Shippers.CompanyName, Customers.CustomerID FROM (Shippers INNER JOIN Customers ON Customers.ShipVia = Shippers.ShipperID) INNER JOIN Orders ON Customers.CustomerID = Orders.OrderID WHERE Shippers.CompanyName = 'Federal Shipping';