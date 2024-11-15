#include <iostream>

enum class QuestState {
    AVAILABLE,
    IN_PROGRESS,
    COMPLETED,
    FAILED
};

enum class ObjectiveState {
    INCOMPLETE,
    COMPLETED
};

class QuestObjective
{
private:
    std::string description;
    ObjectiveState state;
public:
    QuestObjective(const std::string& desc): description(desc), state(ObjectiveState::INCOMPLETE) {}
    void complete() { state = ObjectiveState::COMPLETED; }
    ObjectiveState getState() const { return state; }
    std::string getDescription() const { return description; }
};