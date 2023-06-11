#include <iostream>
#include <string>
#include <vector>

//Met assistentie van ChatGPT
bool isGene(const std::string& gene) {
    std::string forbidden[] = { "ATG", "TAG", "TTA", "TGA" };

    for (const std::string& triplet : forbidden) {
        if (gene.find(triplet) != std::string::npos) {
            return false;
        }
    }

    return gene.length() % 3 == 0;
}

std::vector<std::string> findGenes(const std::string& genome) {
    std::vector<std::string> genes;

    int i = 0;
    while (i < genome.length()) {
        int startIndex = genome.find("ATG", i);
        if (startIndex == std::string::npos) {
            break;
        }
        startIndex += 3;

        std::string list[] = { "TAG", "TTA", "TGA" };
        int endIndex = genome.find(list[0], startIndex);
        for (const std::string& end : list) {
            int en = genome.find(end, startIndex);
            if (en < endIndex && en != std::string::npos) {
                endIndex = en;
            }
        }
        endIndex += 1;
        if (endIndex == std::string::npos) {
            break;
        }

        int length = endIndex - startIndex;
        std::string gene = genome.substr(startIndex, length);

        if (isGene(gene)) {
            genes.push_back(gene);
        }

        i = endIndex + 3;
    }

    return genes;
}

int main() {
    std::string genome;
    std::cout << "Enter a genome string: ";
    std::cin >> genome;

    std::vector<std::string> genes = findGenes(genome);

    if (genes.empty()) {
        std::cout << "No gene found." << std::endl;
    }
    else {
        std::cout << "Genes found:" << std::endl;
        for (const std::string& gene : genes) {
            std::cout << gene << std::endl;
        }
    }

    return 0;
}
