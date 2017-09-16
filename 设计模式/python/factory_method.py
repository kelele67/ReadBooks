import abc

class Foo:
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def wash(self):
        """wash"""

    @abc.abstractmethod
    def sweep(self):
        """sweep"""

    @abc.abstractmethod
    def buy_rice(self):
        """buy rice"""

class Undergraduate(Foo):
    def wash(self):
        print ("Undergraduate wash")

    def sweep(self):
        print ("Undergraduate sweep")

    def buy_rice(self):
        print ("Undergraduate buy_rice")

class Volunteer(Foo):
    def wash(self):
        print ("Volunteer wash")

    def sweep(self):
        print ("Volunteer sweep")

    def buy_rice(self):
        print ("Volunteer buy_rice")

class IFactory:
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def createFoo(self):
        """create class FOO"""

class UndergraduateFactory(IFactory):
    def createFoo(self):
        return Undergraduate()

class VoluteerFactory(IFactory):
    def createFoo(self):
        return Volunteer()

if __name__ == '__main__':
    i_factory = UndergraduateFactory()
    foo = i_factory.createFoo()
    foo.sweep()

    i_factory = VoluteerFactory()
    foo = i_factory.createFoo()
    foo.wash()
