/*/////////////////////////////////////////////////////////////////////////
Student ID#: 148786221
Email : rbehzadfar@myseneca.ca
Section : NRA
Date : 2024 - 03 - 24

Authenticity Declaration :
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.

/////////////////////////////////////////////////////////////////////////*/
#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca {

	 List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
        List<Product> priceList;

        for (size_t i = 0; i < desc.size(); ++i) {
            for (size_t j = 0; j < price.size(); ++j) {
                if (desc[i].code == price[j].code) {
                    Product* temp = new Product(desc[i].desc, price[j].price);
                    try {
                        temp->validate();
                        priceList += temp; // Adds a copy to the list.
                    } catch (const std::string& e) {
                        // Following the logic that could match your expected output:
                        delete temp; // Ensure deletion of the current object.
                        throw; // Rethrow to halt processing if matching output requires stopping at the first error.
                    }
                    delete temp; // Delete after adding because List stores a copy.
                }
            }
            if (i + 1 < desc.size()) {
                // Check if more products are to be processed and manage expectations around destructor calls
            }
        }

        return priceList;
    }


	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;

		// TODO: Add your code here to build a list of products
		//         using smart pointers
    for (auto i = 0u; i < desc.size(); ++i) {
      for (auto j = 0u; j < price.size(); ++j) {
        if (desc[i].code == price[j].code) {
          unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
          temp->validate();
          priceList += temp;
        }
      }
    }

		return priceList;
	}
}