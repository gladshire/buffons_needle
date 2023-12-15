#include <iostream>
#include <vector>
#include <random>
#include <cmath>

const double NEEDLE_LENGTH = 1.0;
const double LINE_SPACING = 1.0;

double buffonNeedlePiApprox(unsigned int numTrials) {

  unsigned int numCrossed = 0;
  
  double randMidCoord;
  double randAngle;
  double lineDistance;
  double probCross;

  // Initialize random number generator
  std::random_device rd;
  std::mt19937 gen(rd());

  // Initialize variable bounds for random number generator
  std::uniform_real_distribution<double> randDist(0.0, LINE_SPACING / 2.0);

  // Perform Monte Carlo simulation over numTrials trials
  for (int i = 0; i < numTrials; i++) {
    randMidCoord = randDist(gen);
    randAngle = randDist(gen) * M_PI;

    lineDistance = (NEEDLE_LENGTH / 2.0) * std::sin(randAngle);

    if (randMidCoord <= lineDistance) {
      numCrossed++;
    }
  }

  // Approximate pi
  probCross = (double)numCrossed / (double) numTrials;
  return (2.0 * NEEDLE_LENGTH) / (LINE_SPACING * probCross);
}





int main() {
  double piApprox;
  std::vector<unsigned int> trialNums = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
  for (int i = 0; i < trialNums.size(); i++) {
    std::cout << "Number of trials: " << std::to_string(trialNums[i]) << std::endl;
    piApprox = buffonNeedlePiApprox(trialNums[i]);
    std::cout << "PI Approximation: " << piApprox << std::endl;
    std::cout << "Percent Error:    " << std::to_string(std::abs(((piApprox - M_PI) / M_PI) * 100.0)) + "%" << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
