#ifndef RESULT_H
#define RESULT_H

#include <ostream>
#include <ctime>
#include <string>
#include <list>

// Stores the information of a complete
// long/short trade (2 entry trades, 2 exit trades).
struct Result {
  
  unsigned id;
  unsigned idExchLong;
  unsigned idExchShort;
  double exposure;
  double feesLong;
  double feesShort;
  std::time_t entryTime;
  std::time_t exitTime;
  std::string exchNameLong;
  std::string exchNameShort;
  double priceLongIn;
  double priceShortIn;
  double priceLongOut;
  double priceShortOut;
  double spreadIn;
  double spreadOut;
  double exitTarget;
  // FIXME: the arrays should have a dynamic size
  double minSpread[13][13];
  double maxSpread[13][13];
  double trailing[13][13];
  unsigned trailingWaitCount[13][13];
  std::list<double> volatility[13][13];
  double leg2TotBalanceBefore;
  double leg2TotBalanceAfter;

  double targetPerfLong()   const;
  double targetPerfShort()  const;
  double actualPerf()       const;
  double getTradeLengthInMinute()             const;
  
  // Prints the entry trade info to the log file
  void printEntryInfo(std::ostream &logFile)  const;
  // Prints the exit trade info to the log file
  void printExitInfo(std::ostream  &logFile)  const;
  
  // Resets the structures
  void reset();
  
  // Tries to load the state from a previous position
  // from the restore.txt file.
  bool loadPartialResult(std::string filename);
  
  // Saves the state from a previous position
  // into the restore.txt file.
  void savePartialResult(std::string filename);
};

#endif
