//What is the largest prime factor of the number 600851475143 ?
//#include "pch.h"

#include <vector>
#include <list>
#include <stdio.h>
#include "Factorset.h"

std::list<long long> Factorset::primeFactors;
std::list<long long> Factorset::nonprimeFactors;
std::list<long long> Factorset::factors;

int main() {
	const long long subject = 600851475143;
	Factorset setone(600851475143);
	setone.printPrimelist();
	return true;
}
