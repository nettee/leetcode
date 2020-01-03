/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum = 0;
        queue<int> q;
        q.push(id);
        while (!q.empty()) {
            int id = q.front();
            Employee* em = find(employees, id);
            sum += em->importance;
            for (int i : em->subordinates) {
                q.push(i);
            }
            q.pop();
        }
        return sum;
    }
    
    Employee* find(vector<Employee*>& ems, int id) {
        for (Employee* em : ems) {
            if (em->id == id) {
                return em;
            }
        }
        return NULL;
    }
};
