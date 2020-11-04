

#include "prj.h"

struct anonApplication  *sortByUniversity(struct anonApplication *head);
struct anonApplication *deleteApplication  (struct anonApplication *head, struct anonApplication *to_be_gone);
struct anonApplication *processDay(struct anonApplication* head, int *clockTime);
void printFormatted (struct anonApplication * head);
void analyzeApplicantList (struct anonApplication * head);
void terminateAndWrite  (struct anonApplication * head);

