/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :07/24/2022
*/
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers

		for (unsigned int i = 0; i < emp.size(); i++) {
			for (unsigned int j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					EmployeeWage employee(emp[i].name, sal[j].salary);
					employee.rangeValidator();
					if (activeEmp.sinValidator(sal[j].id)==false) {
						throw string("wrong SIN number");
					}
					else {
						EmployeeWage* add = &employee;
						activeEmp += add;
					}
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		for (unsigned int i = 0; i < emp.size(); i++) {
			for (unsigned int j = 0; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					unique_ptr<EmployeeWage> employee(new EmployeeWage(emp[i].name, sal[j].salary));
					employee->rangeValidator();
					if (activeEmp.sinValidator(sal[j].id)==false) {
						throw string("wrong SIN number");
					}
					else {
						activeEmp += *employee;
					}
				}
			}
		}
		return activeEmp;
	}
}