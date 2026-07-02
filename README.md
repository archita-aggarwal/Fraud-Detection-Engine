# 🛡️ Fraud Detection Engine (C++)

A rule-based Fraud Detection Engine built in **C++** using **Object-Oriented Programming (OOP)** and **STL**. The project analyzes financial transactions, applies multiple fraud detection rules, calculates a risk score, and generates a final decision along with reports and analytics.

---

# 📌 Project Overview

Online payment systems process thousands of transactions every second. Identifying suspicious or fraudulent transactions quickly is essential to reduce financial losses.

This project simulates a real-world fraud detection engine by evaluating every transaction against multiple fraud detection rules. Depending on the detected risks, the system calculates a fraud score and classifies the transaction as:

- ✅ APPROVED
- ⚠️ MANUAL REVIEW
- ❌ REJECTED

The project follows a modular design where each component has a dedicated responsibility, making it scalable and easy to maintain.

---

# 🚀 Features

### ✅ CSV Transaction Processing
- Reads transaction records from a CSV file.
- Parses and stores transaction details using C++ objects.

### ✅ High Amount Detection
- Detects unusually large transactions based on a configurable threshold.

### ✅ Blacklisted Merchant Detection
- Flags transactions made with merchants present in a blacklist.

### ✅ Night Transaction Detection
- Detects transactions occurring during suspicious night hours.

### ✅ Velocity Rule
- Detects multiple transactions made by the same user within a very short time interval.

### ✅ Impossible Travel Detection
- Detects transactions made from different countries within an unrealistic time gap.

### ✅ User Behaviour Profiling
- Maintains user spending history.
- Detects abnormal spending compared to previous behaviour.

### ✅ Risk Score Calculation
Each triggered fraud rule contributes to an overall fraud score.

### ✅ Decision Engine
Based on the calculated risk score:

| Risk Score | Decision |
|------------|----------|
| 0 - 29 | APPROVED |
| 30 - 69 | MANUAL REVIEW |
| 70+ | REJECTED |

### ✅ Analytics Dashboard
Displays:

- Total Transactions
- Fraud Detected
- Fraud Percentage
- Top Risky Users
- Top Risky Merchants

### ✅ CSV Report Generation
Generates a detailed fraud report for all processed transactions.

### ✅ Logging (Optional Extension)
Stores rejected transactions in a log file for future auditing.

---

# 🏗️ Project Architecture

```
                 Transactions.csv
                        │
                        ▼
                  CSV Reader
                        │
                        ▼
                  Rule Engine
      ┌──────────┬──────────┬──────────┐
      │          │          │          │
 High Amount  Velocity  Blacklist  Behaviour
      │          │          │          │
      └──────────┴──────────┴──────────┘
                        │
                        ▼
                Risk Calculator
                        │
                        ▼
                Decision Engine
                        │
         ┌──────────────┴──────────────┐
         ▼                             ▼
 Report Generator              Analytics Dashboard
```

---

# 📂 Folder Structure

```
FraudDetectionEngine/

├── include/
│   ├── Analytics.h
│   ├── BlacklistLoader.h
│   ├── CSVReader.h
│   ├── DecisionEngine.h
│   ├── Logger.h
│   ├── ReportGenerator.h
│   ├── RiskCalculator.h
│   ├── RuleEngine.h
│   ├── TimeUtils.h
│   ├── Transaction.h
│   └── UserProfile.h
│
├── src/
│   ├── Analytics.cpp
│   ├── BlacklistLoader.cpp
│   ├── CSVReader.cpp
│   ├── DecisionEngine.cpp
│   ├── Logger.cpp
│   ├── ReportGenerator.cpp
│   ├── RiskCalculator.cpp
│   ├── RuleEngine.cpp
│   ├── TimeUtils.cpp
│   ├── UserProfile.cpp
│   └── main.cpp
│
├── data/
│   ├── transactions.csv
│   └── blacklist.csv
│
├── output/
│   └── fraud_report.csv
│
├── logs/
│   └── fraud.log
│
├── README.md
└── LICENSE
```

---

# 🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL
- Vectors
- Unordered Map
- Unordered Set
- File Handling
- CSV Parsing
- Modular Programming

---

# 📊 Fraud Detection Rules

| Rule | Description |
|------|-------------|
| High Amount | Detects unusually high-value transactions |
| Blacklisted Merchant | Checks transactions against a blacklist |
| Night Transaction | Detects transactions during suspicious hours |
| Velocity Rule | Detects rapid consecutive transactions |
| Impossible Travel | Detects transactions from different countries in a short time |
| Behaviour Profiling | Detects abnormal spending based on user history |

---

# 📈 Sample Output

```
--------------------------------
Txn ID : 1008
Amount : 950000
Merchant : Crypto Exchange

Risk Score : 70

Decision : REJECTED

Reasons

- High Amount
- Blacklisted Merchant
```

Dashboard

```
============================
Fraud Dashboard
============================

Total Transactions : 13

Fraud Detected : 1

Fraud Rate : 7.69 %

Top Risky Users

U004 -> 1

Top Risky Merchants

Crypto Exchange -> 1
```

---

# ▶️ How to Compile

Using g++

```bash
g++ src/*.cpp -o FraudDetectionEngine.exe
```

Run

```bash
./FraudDetectionEngine.exe
```

---

# 💡 OOP Concepts Used

- Classes & Objects
- Encapsulation
- Modular Design
- Data Abstraction
- Separation of Concerns

---

# 📚 Learning Outcomes

This project demonstrates practical implementation of:

- Rule-based Fraud Detection
- Financial Transaction Analysis
- Behaviour Profiling
- Risk Assessment
- File Processing
- Data Structures using STL
- Software Design using OOP
- Modular C++ Development

---

# 🔮 Future Enhancements

- Machine Learning based fraud prediction
- Database integration (MySQL/PostgreSQL)
- REST API support
- Real-time transaction monitoring
- Configuration file for fraud thresholds
- Interactive dashboard
- Unit Testing

---

# 👨‍💻 Author

**Archita Aggarwal**

B.Tech Student

Project: **Fraud Detection Engine (C++)**

---

# ⭐ Conclusion

The Fraud Detection Engine is a modular and extensible C++ application that simulates how modern financial institutions identify suspicious transactions using multiple rule-based techniques. The project combines OOP principles, STL containers, file handling, analytics, and reporting to create a realistic fraud detection workflow while maintaining clean architecture and scalability.