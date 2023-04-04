-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jul 29, 2022 at 08:53 AM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 8.1.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cosmic_library`
--

-- --------------------------------------------------------

--
-- Table structure for table `author`
--

CREATE TABLE `author` (
  `Author_ID` varchar(50) NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Address` varchar(50) DEFAULT NULL,
  `Contact_no` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `author`
--

INSERT INTO `author` (`Author_ID`, `Name`, `Address`, `Contact_no`) VALUES
('A01', 'Ramez Elmasri', 'Kathmandu', 9812456043),
('A02', 'C.J. Date', 'Kathmandu', 9827454065),
('A03', 'Hirohiko Araki', 'Pokhara', 9846790612),
('A04', 'Tatsuki Fujimoto', 'Pokhara', 9804372724),
('A05', 'Eiichiro Oda', 'Pokhara', 9838560378);

-- --------------------------------------------------------

--
-- Table structure for table `book`
--

CREATE TABLE `book` (
  `Book_ID` varchar(50) NOT NULL,
  `ISBN` varchar(17) DEFAULT NULL,
  `Title` varchar(50) DEFAULT NULL,
  `Field` varchar(50) DEFAULT NULL,
  `Publisher_ID` varchar(50) DEFAULT NULL,
  `Author_ID` varchar(50) DEFAULT NULL,
  `Edition` date DEFAULT NULL,
  `Category` varchar(50) DEFAULT NULL,
  `Status` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `book`
--

INSERT INTO `book` (`Book_ID`, `ISBN`, `Title`, `Field`, `Publisher_ID`, `Author_ID`, `Edition`, `Category`, `Status`) VALUES
('B01', '0-5540-2036-X', 'Introduction to Databases', 'Computing', 'P06', 'A02', '2019-03-01', 'Yellow-tag', 'loaned out'),
('B02', '0-2495-9413-7', 'Biology', 'Science', 'P05', 'A03', '2020-03-01', 'Green-tag', 'available'),
('B03', '0-5540-2036-X', 'Introduction to Databases', 'Computing', 'P06', 'A02', '2019-03-01', 'Yellow-tag', 'available'),
('B04', '0-6161-9434-X', 'Introduction to C', 'Computing', 'P06', 'A01', '2021-01-07', 'Green-tag', 'available'),
('B05', '0-6161-9434-X', 'Introduction to C', 'Computing', 'P06', 'A01', '2021-01-07', 'Green-tag', 'loaned out'),
('B06', '0-2717-7834-2', 'Physics', 'Science', 'P03', 'A03', '2020-05-21', 'Yellow-tag', 'available'),
('B07', '0-2495-9413-7', 'Biology', 'Science', 'P05', 'A03', '2020-03-01', 'Green-tag', 'loaned out'),
('B08', '0-2495-9413-7', 'Introdution to Networking', 'Computing', 'P04', 'A04', '2020-03-01', 'Green-tag', 'available'),
('B09', '0-3094-5662-2', 'Biology Project', 'Project Work', 'P05', 'A05', '2019-01-01', 'Red-tag', 'not available'),
('B10', '0-1284-8631-7', 'System Analysis and Design', 'Computing', 'P05', 'A02', '2019-06-01', 'Green-tag', 'loaned out'),
('B11', '0-2495-9413-7', 'Introdution to Networking', 'Computing', 'P04', 'A04', '2020-03-01', 'Green-tag', 'loaned out'),
('B12', '0-8549-3165-1', 'Python Programming', 'Computing', 'P01', 'A03', '2019-02-03', 'Green-tag', 'loaned out'),
('B13', '0-8549-3165-1', 'Python Programming', 'Computing', 'P01', 'A03', '2019-02-03', 'Green-tag', 'loaned out'),
('B14', '0-8549-3165-1', 'Python Programming', 'Computing', 'P01', 'A03', '2018-05-08', 'Green-tag', 'available'),
('B15', '0-2334-4303-7', 'Accounting', 'Management', 'P02', 'A01', '2021-04-11', 'Green-tag', 'loaned out'),
('B16', '0-1378-9700-6', 'Marketing', 'Management', 'P05', 'A04', '2020-01-03', 'Yellow-tag', 'loaned out');

-- --------------------------------------------------------

--
-- Table structure for table `classification`
--

CREATE TABLE `classification` (
  `Classify_ID` varchar(50) NOT NULL,
  `Classify_Name` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `classification`
--

INSERT INTO `classification` (`Classify_ID`, `Classify_Name`) VALUES
('LR-01', 'Lecturer'),
('SD-02', 'Student'),
('SF-03', 'Staff');

-- --------------------------------------------------------

--
-- Table structure for table `member`
--

CREATE TABLE `member` (
  `Member_ID` varchar(50) NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Department` varchar(50) DEFAULT NULL,
  `Status` varchar(50) DEFAULT NULL,
  `Classify_ID` varchar(50) DEFAULT NULL,
  `Email_ID` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `member`
--

INSERT INTO `member` (`Member_ID`, `Name`, `Department`, `Status`, `Classify_ID`, `Email_ID`) VALUES
('MR01', 'Charolette Katakuri', 'IT', 'active', 'SD-02', 'mochidonuts57@gmail.com'),
('MR02', 'Erza Scarlet', 'Arts', 'inactive', 'SD-02', 'titania_qof@gmail.com'),
('MR03', 'Irina Jelavic', 'English', 'active', 'LR-01', 'vich_sensei@gmail.com'),
('MR04', 'Shoto Todoroki', 'Science', 'active', 'SD-02', 'half_n_half@gmail.com'),
('MR05', 'Lucy Heartfilia', 'English', 'active', 'SD-02', 'celestialmage10@gmail.com'),
('MR06', 'Vinsmoke Reiju', 'IT', 'active', 'SD-02', 'poisonpink0000@gmail.com'),
('MR07', 'Nico Robin', 'History', 'active', 'LR-01', 'missallsunday@gmail.com'),
('MR08', 'Satoru Gojo', 'IT', 'inactive', 'LR-01', 'thestrongest@gmail.com'),
('MR09', 'Shigeo Kageyama', 'Management', 'active', 'SD-02', 'mobpsycho100@gmail.com'),
('MR10', 'Dr. Vegapunk', 'Science', 'active', 'LR-01', 'buzzfeedunsolved@gmail.com'),
('MR11', 'Koro-sensei', 'Humanities', 'inactive', 'LR-01', 'mach20octopus@gmail.com'),
('MR12', 'Silvers Rayleigh', 'Management', 'inactive', 'LR-01', 'dark_king@gmail.com'),
('MR13', 'Laxus Dreyar', 'Head-Librarian', 'active', 'SF-03', '2ndgenfairylaw@gmail.com'),
('MR14', 'Yami Sukehiro', 'Head-Librarian', 'inactive', 'SF-03', 'blackbullscaptain@gmail.com'),
('MR15', 'Levy McGarden', 'Assistant Librarian', 'active', 'SF-03', 'ironhead@gmail.com'),
('MR16', 'Amajiki', 'Assistant Librarian', 'active', 'SF-03', 'buffama@gmail.com'),
('MR17', 'Jellal Fernandez', 'Assistant Librarian', 'inactive', 'SF-03', 'justsomeguywithoutamustache@gmail.com'),
('MR18', 'Denji', 'Arts', 'inactive', 'SD-02', 'chainsawheart@gmail.com'),
('MR19', 'Aki Hayakawa', 'Humanities', 'inactive', 'SD-02', 'snowballgun@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `publisher`
--

CREATE TABLE `publisher` (
  `Publisher_ID` varchar(50) NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Address` varchar(50) DEFAULT NULL,
  `Email_ID` varchar(50) DEFAULT NULL,
  `Contact_no` bigint(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `publisher`
--

INSERT INTO `publisher` (`Publisher_ID`, `Name`, `Address`, `Email_ID`, `Contact_no`) VALUES
('P01', 'Dio Brando', 'Pokhara', 'mudamudamuda@gmail.com', 9821373185),
('P02', 'Joseph Joestar', 'Pokhara', 'ohhmygod@gmail.com', 9843132186),
('P03', 'Jotaro Kujo', 'Pokhara', 'oraoraora@gmail.com', 9812150137),
('P04', 'Josuke Higashikata', 'Pokhara', 'dorarara@gmail.com', 9838456734),
('P05', 'Giorno Giovanna', 'Pokhara', 'ihaveadream@gmail.com', 9804679372),
('P06', 'Prentice hall', 'Kathmandu', 'prenticehall@gmail.com', 9843167832);

-- --------------------------------------------------------

--
-- Table structure for table `reservation`
--

CREATE TABLE `reservation` (
  `Member_ID` varchar(50) DEFAULT NULL,
  `Book_ID` varchar(50) DEFAULT NULL,
  `Reservation_date` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `reservation`
--

INSERT INTO `reservation` (`Member_ID`, `Book_ID`, `Reservation_date`) VALUES
('M06', 'B13', '2022-04-20'),
('M03', 'B03', '2022-03-25'),
('M05', 'B06', '2022-03-10'),
('M01', 'B07', '2022-04-05'),
('M09', 'B16', '2022-04-10'),
('M07', 'B02', '2022-03-17'),
('MR06', 'B13', '2022-04-20'),
('MR03', 'B03', '2022-03-25'),
('MR05', 'B06', '2022-03-10'),
('MR01', 'B07', '2022-04-05'),
('MR09', 'B16', '2022-04-10'),
('MR07', 'B02', '2022-03-17'),
('MR16', 'B05', '2022-04-06'),
('MR15', 'B14', '2022-05-13');

-- --------------------------------------------------------

--
-- Table structure for table `transaction`
--

CREATE TABLE `transaction` (
  `Transaction_ID` varchar(50) NOT NULL,
  `Member_ID` varchar(50) DEFAULT NULL,
  `Book_ID` varchar(50) DEFAULT NULL,
  `Borrow_date` date DEFAULT NULL,
  `Return_date` date DEFAULT NULL,
  `Actual_Return_date` date DEFAULT NULL,
  `Fine` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `transaction`
--

INSERT INTO `transaction` (`Transaction_ID`, `Member_ID`, `Book_ID`, `Borrow_date`, `Return_date`, `Actual_Return_date`, `Fine`) VALUES
('TI01', 'MR01', 'B10', '2019-07-08', '2019-07-19', '2019-07-24', 50),
('TI02', 'MR10', 'B07', '2021-03-16', '2021-04-16', '2021-04-10', 0),
('TI03', 'MR01', 'B05', '2021-04-05', '2021-04-20', '2021-04-18', 0),
('TI04', 'MR04', 'B02', '2020-03-19', '2022-03-20', '2022-03-25', 50),
('TI05', 'MR01', 'B01', '2019-03-19', '2019-03-28', '2019-03-25', 0),
('TI06', 'MR01', 'B11', '2020-04-09', '2020-04-19', '2020-04-29', 100),
('TI07', 'MR07', 'B15', '2021-04-23', '2020-05-23', '2021-05-29', 120),
('TI08', 'MR01', 'B13', '2021-12-10', '2021-12-26', NULL, NULL),
('TI09', 'MR06', 'B14', '2022-02-07', '2022-03-07', '2022-03-25', 360),
('TI10', 'MR06', 'B12', '2022-01-03', '2022-01-19', NULL, NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `author`
--
ALTER TABLE `author`
  ADD PRIMARY KEY (`Author_ID`);

--
-- Indexes for table `book`
--
ALTER TABLE `book`
  ADD PRIMARY KEY (`Book_ID`),
  ADD KEY `fk_MemberID` (`Author_ID`),
  ADD KEY `fk_PublisherID` (`Publisher_ID`);

--
-- Indexes for table `classification`
--
ALTER TABLE `classification`
  ADD PRIMARY KEY (`Classify_ID`);

--
-- Indexes for table `member`
--
ALTER TABLE `member`
  ADD PRIMARY KEY (`Member_ID`),
  ADD KEY `fk_Classify_ID` (`Classify_ID`);

--
-- Indexes for table `publisher`
--
ALTER TABLE `publisher`
  ADD PRIMARY KEY (`Publisher_ID`);

--
-- Indexes for table `reservation`
--
ALTER TABLE `reservation`
  ADD KEY `fk_Member_ID1` (`Member_ID`),
  ADD KEY `fk_Book_ID1` (`Book_ID`);

--
-- Indexes for table `transaction`
--
ALTER TABLE `transaction`
  ADD PRIMARY KEY (`Transaction_ID`),
  ADD KEY `fk_Member_ID1001` (`Member_ID`),
  ADD KEY `fk_Book_ID` (`Book_ID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `book`
--
ALTER TABLE `book`
  ADD CONSTRAINT `fk_MemberID` FOREIGN KEY (`Author_ID`) REFERENCES `author` (`Author_ID`),
  ADD CONSTRAINT `fk_PublisherID` FOREIGN KEY (`Publisher_ID`) REFERENCES `publisher` (`Publisher_ID`);

--
-- Constraints for table `member`
--
ALTER TABLE `member`
  ADD CONSTRAINT `fk_Classify_ID` FOREIGN KEY (`Classify_ID`) REFERENCES `classification` (`Classify_ID`);

--
-- Constraints for table `reservation`
--
ALTER TABLE `reservation`
  ADD CONSTRAINT `fk_Book_ID1` FOREIGN KEY (`Book_ID`) REFERENCES `book` (`Book_ID`),
  ADD CONSTRAINT `fk_Member_ID1` FOREIGN KEY (`Member_ID`) REFERENCES `member` (`Member_ID`);

--
-- Constraints for table `transaction`
--
ALTER TABLE `transaction`
  ADD CONSTRAINT `fk_Book_ID` FOREIGN KEY (`Book_ID`) REFERENCES `book` (`Book_ID`),
  ADD CONSTRAINT `fk_Member_ID1001` FOREIGN KEY (`Member_ID`) REFERENCES `member` (`Member_ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
