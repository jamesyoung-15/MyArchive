class UPerson                      /* File: v-uperson2.h */
{
  public: virtual ~UPerson() = default;
  ...
};

class Student : public UPerson     /* File: v-student2.h */
{
  public:
    virtual ~Student()
    {
        for (int j = 0; j < num_courses; ++j)
            delete enrolled[j];
    }
  ...
};
