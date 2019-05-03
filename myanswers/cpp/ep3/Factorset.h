#pragma once
class Factorset {
private:
	long long n;
	bool isPrime = false;

public:
	static std::list<long long> primeFactors;
	static std::list<long long> nonprimeFactors;
	static std::list<long long> factors;

	void add2PrimeList(const long long prime) {
		primeFactors.push_back(prime);
		primeFactors.unique();
		primeFactors.sort();
	}

	void add2NonPrimeList(const long long nprime) {
		nonprimeFactors.push_back(nprime);
		nonprimeFactors.unique();
		nonprimeFactors.sort();
	}

	void add2FactorList(const long long factor) {
		factors.push_back(factor);
		factors.unique();
		factors.sort();
	}
	
	Factorset(const long long n) {
		this->n = n;
		this->isPrime = checkPrimeIni(n);
		processfactor();
		processnonprime();
	}

	bool checkPrimeIni(const long long n) {
		bool temp = true;
		if ((n % 2) == 0) {
			add2FactorList(2);
			add2FactorList(n/2);
			temp = false;
		}
		long long limit = sqrt(n);
		for (long index = 3; index < limit; ++(++index)) {
			if ((n % index) == 0) {
				add2FactorList(index);
				add2FactorList(n/index);
				temp = false;
			}
		}
		return temp;
	}

	void printPrimelist() {
		int primeFactorIndex = 1;
		for (auto primeFactor : primeFactors) {
			printf("#%d\tprime facter is %lld\n", primeFactorIndex, primeFactor);
			++primeFactorIndex;
		}
	}

	void printNonPrimelist() {
		int nonprimeFactorIndex = 1;
		for (auto nonprimeFactor : nonprimeFactors) {
			printf("#%d\tnon-prime facter is %lld\n", nonprimeFactorIndex, nonprimeFactor);
			++nonprimeFactorIndex;
		}
	}

	void processfactor() {
		for (auto it = factors.begin(); it != factors.end(); ++it) {
			if (checkPrimeIni(*it)) {
				add2PrimeList(*it);
			}
			else {
				add2NonPrimeList(*it);
			}
		}
	}

	void processnonprime() {
		for (auto it = nonprimeFactors.begin(); it != nonprimeFactors.end(); ++it) {
			if (checkPrimeIni(*it)) {
				add2PrimeList(*it);
			}
			else
				Factorset(*it);
		}
	}
};
