#ifndef FQ_MARKETDATA_BOGUSPROVODER_H
#define FQ_MARKETDATA_BOGUSPROVODER_H

#include <set>
#include <freequant/marketdata/MarketDataProvider.h>
#include <freequant/utils/MarketDataGenerator.h>

namespace FreeQuant {

class Strategy;

class BogusMarketDataProvider : public MarketDataProvider {
public:
    typedef MarketDataProvider::Symbols Symbols;
    explicit BogusMarketDataProvider(Strategy *strategy = 0);
    ~BogusMarketDataProvider() {}

    void setCallback(MarketDataProvider::Callback *callback);
    void setCallback(MarketDataProviderCallback *callback);
    void connect(bool block = true);
    void disconnect(bool block = true);
    bool isConnected() const { return _connected; }
    std::string name() const { return "Bogus"; }
    void subscribe(const Symbols&);
    void unsubscribe(const Symbols&);
    void generateBars();
    void subscribe(const std::string& symbol);
    void unsubscribe(const std::string& symbol);

private:
    bool _connected;

    MarketDataProvider::Callback *_callback;
    Strategy *_strategy;
    boost::shared_ptr<MarketDataGenerator> _mdGenerator;
};

} // namespace FreeQuant

#endif // FQ_MARKETDATA_BOGUSPROVODER_H
