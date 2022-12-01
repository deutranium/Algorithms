--- Sort an array using the cocktail sort algorithm.
--- @param t table
--- @return table
local function cocktailSort(t)
    local n = #t
    local swapped = true
    local start = 1
    local end_ = n - 1
    while swapped do
        swapped = false
        for i = start, end_ do
            if t[i] > t[i + 1] then
                t[i], t[i + 1] = t[i + 1], t[i]
                swapped = true
            end
        end
        if not swapped then
            break
        end
        swapped = false
        end_ = end_ - 1
        for i = end_, start, -1 do
            if t[i] < t[i - 1] then
                t[i], t[i - 1] = t[i - 1], t[i]
                swapped = true
            end
        end
        start = start + 1
    end
    return t
end

return cocktailSort