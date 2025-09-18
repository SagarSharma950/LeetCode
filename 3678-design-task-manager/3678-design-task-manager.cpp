class TaskManager {
    struct Task {
        int userId;
        int taskId;
        int priority;
    };
    struct Compare {
        bool operator()(const Task& a, const Task& b) const {
            if (a.priority == b.priority) return a.taskId < b.taskId;
            return a.priority < b.priority;
        }
    };

    priority_queue<Task, vector<Task>, Compare> pq;
    unordered_map<int, pair<int,int>> taskMap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) add(t[0], t[1], t[2]);
    }

    void add(int userId, int taskId, int priority) {
        pq.push({userId, taskId, priority});
        taskMap[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            int userId = it->second.first;
            it->second.second = newPriority;
            pq.push({userId, taskId, newPriority});
        }
    }

    void rmv(int taskId) {
        taskMap.erase(taskId);
    }

    int execTop() {
        while (!pq.empty()) {
            Task t = pq.top(); pq.pop();
            auto it = taskMap.find(t.taskId);
            if (it != taskMap.end() && it->second.first == t.userId && it->second.second == t.priority) {
                taskMap.erase(it);
                return t.userId;
            }
        }
        return -1;
    }
};