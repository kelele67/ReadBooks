# import threading

# class Singleton(object):
#     """Singleton"""
#     instance = None
#     lock = threading.RLock()

#     @classmethod
#     def __new__(cls):
#         if cls.instance is None:
#             cls.lock.acquire()
#             if cls.instance is None:
#                 cls.instance = super(Singleton, cls).__new__(cls)
#             cls.lock.release()
#         return cls.instance

# if __name__ == '__main__':
#     instance1 = Singleton()
#     instance2 = Singleton()
#     print (id(instance1) == id(instance2))

# class Singleton(object):
#     def __new__(cls):
#         if not hasattr(cls, '_instance'):
#             cls._instance = super(Singleton, cls).__new__(cls)
#         return cls._instance

# if __name__ == '__main__':
#     class A(Singleton):
#         def __init__(self, s):
#             self.s = s
#     a = A('apple')
#     b = A('banana')

#     print (id(a), a.s)
#     print (id(b), b.s)

