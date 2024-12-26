class Test:
    def __init__(self,init_n:int):
        if type(init_n) != int:
            raise TypeError("n must be an integer")
        self.n = init_n

    def getn(self):
        return self.__dict__['n'] ** 2

    def setn(self,rhs_object):
        self.__dict__['n'] = rhs_object
    
    def deln(self):
        raise AttributeError("attribute n can not be removed")
    

    n = property(getn,setn,deln)


t = Test(100)
print(t.n)
t.n=30
print(t.n)

try:
    del t.n
except AttributeError as e:
    print(e)