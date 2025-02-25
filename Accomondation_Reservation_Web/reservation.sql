-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Jul 28, 2023 at 02:24 PM
-- Server version: 10.5.20-MariaDB
-- PHP Version: 7.3.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `id19659168_reserveform`
--

-- --------------------------------------------------------

--
-- Table structure for table `reservation`
--

CREATE TABLE `reservation` (
  `personal_id` varchar(50) NOT NULL,
  `firstName` varchar(50) NOT NULL,
  `lastName` varchar(50) NOT NULL,
  `phone` varchar(50) NOT NULL,
  `email` varchar(50) NOT NULL,
  `destination` varchar(50) NOT NULL,
  `accomodation` varchar(50) NOT NULL,
  `food` varchar(50) NOT NULL,
  `stay_days` int(5) NOT NULL,
  `accom_min_value` int(5) NOT NULL,
  `hotel_name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `reservation`
--

INSERT INTO `reservation` (`personal_id`, `firstName`, `lastName`, `phone`, `email`, `destination`, `accomodation`, `food`, `stay_days`, `accom_min_value`, `hotel_name`) VALUES
('ccb8c5228131a4f45ee7fefc21ca0984', 'Μαρία', 'Δημητροπούλου', '6979797979', 'mariadimitropoulou1999@gmail.com', 'Κέρκυρα', 'Μονόκλινο', 'Πλήρης_Διατροφή', 20, 4000, 'Corfu Beach'),
('229f9e2334dcbafc06e2b6bcec5e60e5', 'vvv', 'vvv', '6900000000', 'marios@gmail.com', 'Ρόδος', 'Τρίκλινο', 'Πλήρης_Διατροφή', 2, 620, 'Lindos Accomodation');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
